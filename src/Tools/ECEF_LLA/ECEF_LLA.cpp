#include "ECEF_LLA.h"

#include <limits>

// 辅助函数：角度转弧度
inline double deg2rad(double deg) {
    return deg * M_PI / 180.0;
}

// 辅助函数：弧度转角度
inline double rad2deg(double rad) {
    return rad * 180.0 / M_PI;
}

// ECEF转LLA (迭代法计算纬度)
LLA ecefToLLA(const ECEF& ecef) {
    const double x = ecef.x;
    const double y = ecef.y;
    const double z = ecef.z;

    // 计算经度（直接解析解）
    const double lambda = atan2(y, x);

    // 计算纬度（需迭代）
    const double p = sqrt(x * x + y * y);
    double phi = atan2(z, p * (1.0 - WGS84_E * WGS84_E)); // 初始估计
    double h = 0.0;
    double delta_h = std::numeric_limits<double>::max();
    const double tolerance = 1e-6; // 收敛阈值 [m]

    // 迭代求解纬度和高度
    for (int i = 0; i < 100 && delta_h > tolerance; ++i) {
        const double sin_phi = sin(phi);
        const double N = WGS84_A / sqrt(1.0 - WGS84_E * WGS84_E * sin_phi * sin_phi);
        h = p / cos(phi) - N;
        const double phi_new = atan2(z, p * (1.0 - WGS84_E * WGS84_E * N / (N + h)));
        delta_h = fabs(phi_new - phi);
        phi = phi_new;
    }

    return {
        rad2deg(lambda),
        rad2deg(phi),
        h
    };
}

// LLA转ECEF (直接公式)
ECEF llaToECEF(const LLA& lla) {
    const double lambda = deg2rad(lla.lon);
    const double phi = deg2rad(lla.lat);
    const double h = lla.alt;

    const double sin_phi = sin(phi);
    const double cos_phi = cos(phi);
    const double sin_lambda = sin(lambda);
    const double cos_lambda = cos(lambda);

    // 计算卯酉圈曲率半径
    const double N = WGS84_A / sqrt(1.0 - WGS84_E * WGS84_E * sin_phi * sin_phi);

    return {
        (N + h) * cos_phi * cos_lambda,
        (N + h) * cos_phi * sin_lambda,
        (N * (1.0 - WGS84_E * WGS84_E) + h) * sin_phi
    };
}

// 计算两点之间的欧氏距离
double distance(const ECEF& a, const ECEF& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dz = b.z - a.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// 归一化向量（单位化）
ECEF normalize(const ECEF& v) {
    double norm = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (norm == 0.0) {
        throw std::runtime_error("Cannot normalize a zero vector.");
    }
    return { v.x / norm, v.y / norm, v.z / norm };
}

// 从起点 start 沿 end 方向移动 displacement 距离
ECEF moveTowards(const ECEF& start, const ECEF& end, double displacement) {
    // 计算方向向量
    ECEF direction = { end.x - start.x, end.y - start.y, end.z - start.z };

    // 归一化方向向量
    ECEF unit_direction = normalize(direction);

    // 计算新坐标
    ECEF new_point = {
        start.x + unit_direction.x * displacement,
        start.y + unit_direction.y * displacement,
        start.z + unit_direction.z * displacement
    };

    return new_point;
}
