#ifndef ENGINE3D_H
#define ENGINE3D_H

#include <iostream>
#include <vector>
#include <tgmath.h>

using namespace std;

// Structs for 3d rendering
struct vec3d
{
  float x, y, z;
};

struct triangle
{
  vec3d p[3];
};

struct mesh
{
	vector<triangle> tris; 
};

struct mat4x4
{
  float m[4][4] = { 0 };
};

// 3d engine class
class Engine3d
{
public:
  Engine3d();
  ~Engine3d();

	void DrawTriangle();
	void fill();

  bool OnUserCreate() {
			
    // Projection Matrix
    float fNear = 0.1f;
    float fFar = 1000.0f;
    float fFov = 90.0f;
    float fAspectRatio = (float)ScreenHeight() / (float)ScreenWidth();
    float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);
	};

  bool OnUserUpdate(float fElapsedTime);

private:
  mesh meshCube;
  mat4x4 matProj;
	triangle triProjected;

  void MultiplyMatrixVector(vec3d &i, vec3d &o, mat4x4 &m);
};

#endif
// source: https://www.youtube.com/watch?v=ih20l3pJoeU&list=PL2AaJ-EqyFmoW5xYjh9n--283yhoVEMkq&index=4
