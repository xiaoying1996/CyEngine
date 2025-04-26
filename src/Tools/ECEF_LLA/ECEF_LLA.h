#ifndef ECEF_LLA_HPP
#define ECEF_LLA_HPP

#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// WGS84�������
constexpr double WGS84_A = 6378137.0;          // �볤�� [m]
constexpr double WGS84_F = 1.0 / 298.257223563; // ����
const double WGS84_E = sqrt(2 * WGS84_F - WGS84_F * WGS84_F); // ��һƫ����

// ECEF����ṹ��
struct ECEF {
    double x; // X������ [m]
    double y; // Y������ [m]
    double z; // Z������ [m]
};

// ��γ�߽ṹ�� (LLA)
struct LLA {
    double lon; // ���� [��]
    double lat; // γ�� [��]
    double alt; // �߶� [m]
};

// ECEFתLLA
LLA ecefToLLA(const ECEF& ecef);

// LLAתECEF
ECEF llaToECEF(const LLA& lla);

double distance(const ECEF& a, const ECEF& b);
ECEF normalize(const ECEF& v);
ECEF moveTowards(const ECEF& start, const ECEF& end, double displacement);

#endif // ECEF_LLA_HPP