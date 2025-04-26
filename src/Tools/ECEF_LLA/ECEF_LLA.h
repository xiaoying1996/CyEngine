#ifndef ECEF_LLA_HPP
#define ECEF_LLA_HPP

#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// WGS84椭球参数
constexpr double WGS84_A = 6378137.0;          // 半长轴 [m]
constexpr double WGS84_F = 1.0 / 298.257223563; // 扁率
const double WGS84_E = sqrt(2 * WGS84_F - WGS84_F * WGS84_F); // 第一偏心率

// ECEF坐标结构体
struct ECEF {
    double x; // X轴坐标 [m]
    double y; // Y轴坐标 [m]
    double z; // Z轴坐标 [m]
};

// 经纬高结构体 (LLA)
struct LLA {
    double lon; // 经度 [度]
    double lat; // 纬度 [度]
    double alt; // 高度 [m]
};

// ECEF转LLA
LLA ecefToLLA(const ECEF& ecef);

// LLA转ECEF
ECEF llaToECEF(const LLA& lla);

double distance(const ECEF& a, const ECEF& b);
ECEF normalize(const ECEF& v);
ECEF moveTowards(const ECEF& start, const ECEF& end, double displacement);

#endif // ECEF_LLA_HPP