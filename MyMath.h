#pragma once
#include <Novice.h>
#include <cmath>
#include <assert.h>

//三次元ベクトル
struct Vector3
{
	float x, y, z;

	Vector3 operator-() const {
		return { -x, -y, -z };
	}
};

//四次元ベクトル
struct Vector4
{
	float x, y, z, w;
};

//行列
struct Matrix4x4
{
	float m[4][4];
};

//球
struct Sphere
{
	Vector3 center;///!<中心点
	float radius;  ///!<半径
};

//四元数
struct Quaternion
{
	float x;
	float y;
	float z;
	float w;
};

//結果の描画

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);
void QuaternionScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label);

///MT3_00-01///

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);
//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
//スカラー倍
Vector3 scalar(float scalar, const Vector3& v);
//内積
float Dot(const Vector3& v1, const Vector3& v2);
//長さ(ノルム)
float Length(const Vector3& v);
//正規化
Vector3 Normalize(const Vector3& v);

///MT3_00-02///

//1.行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
//2.行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
//3.行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
//4.逆行列
Matrix4x4 Inverse(const Matrix4x4& m);
//5.転置行列
Matrix4x4 Transpose(const Matrix4x4& m);
//6.単位行列
Matrix4x4 MakeIdentity4x4();

///MT3_00-03///

//1.平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
//2.拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale);
//3.座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

///MT3_00-04///

//1.X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian);
//2.Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian);
//3.Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian);

///MT3_00-05///

//三次元アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

///MT3_01-00///

//1.透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float forY, float aspectRatio, float nearClip, float farClip);
//2.正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
//3.ピューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

///MT3_01-01///

//クロス積
Vector3 Cross(const Vector3& v1, const Vector3& v2);

///MT3_01-02///

//カメラ視点行列
Matrix4x4 MakeViewMatrix(const Vector3& translate, const Vector3& rotate);
//Gridを表示する疑似コード
void DrawGrid(const Matrix4x4& viewProjectMatrix, const Matrix4x4& viewportMatrix);
//球の表示
void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

///01-01///

//任意軸回転の回転行列
Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

///01-02///
//ある方向からある方向への回転行列
Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);

///01-03///

//Quaternionの積
Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);
//単位Quaternionを返す
Quaternion IdentityQuaternion();
//共役Quaternionのを返す
Quaternion Conjugate(const Quaternion& quaternion);
//Quaternionのnormを返す
float Norm(const Quaternion& quaternion);
//正規化したQuaternionのを返す
Quaternion Normalize(const Quaternion& quaternion);
//逆Quaternionのを返す
Quaternion Inverse(const Quaternion& quaternion);