#ifndef ENGINE3D_H
#define ENGINE3D_H

#include <iostream>
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
	vector<triangle> tris 
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

  bool OnUserCreate() {
    meshCube.tris = {
      // SOUTH SIDE
      {0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f},
      {0.0f, 0.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 0.0f, 0.0f},

      // EAST SIDE
			{1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f},
			{1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f,  1.0f, 0.0f, 1.0f},

      // NORTH SIDE
      {1.0f, 0.0f, 1.0f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f},
      {1.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f},

      // WEST SIDE
      {0.4f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 0.0f},
      {0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 0.0f, 0.0f},

      // TOP SIDE
      {0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f},
      {0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 0.0f},

      // BOTTOM SIDE
      {1.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 0.0f},
      {1.0f, 0.0f, 1.0f,  0.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f}
    }

    // Projection Matrix
    float fNear = 0.1f;
    float fFar = 1000.0f;
    float fFov = 90.0f;
    float fAspectRatio = (float)ScreenHeight() / (float)ScreenWidth();
    float fFovRad = 1.0f / tanf(fFoc * 0.5f / 180.0f * 3.14159f);
 
    matProj.m[0][0] = fAspectRation * fFovRad;
    matProj.m[1][1] = fFovRad;
    matProj.m[2][2] = fFar / (fFar - fNear)
    matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
    matProj.m[2][3] = 1.0f;
    matProj.m[3][3] = 0.0f;

    return true;
  };

  bool OneUserUpdate(float fElapsedTime) {

    Fill(0, 0, ScreenWidth, ScreenHeight(), PIXEL_SOLID, FG_BLACK);

    // Draw Triangles
    for (auto tri : meshCube.tris)
    {
      triangle triProjected;
      MultiplyMatrixVector(tri.p[0].x, triProjected.p[0], matProj);
      MultiplyMatrixVector(tri.p[1].x, triProjected.p[1], matProj);
      MultiplyMatrixVector(tri.p[2].x, triProjected.p[2], matProj);

			//Scale into view
			triProjected.p[0].x += 1.0f; triProjected.p[0].x += 1.0f;
			triProjected.p[1].x += 1.0f; triProjected.p[1].x += 1.0f;
			triProjected.p[2].x += 1.0f; triProjected.p[2].x += 1.0f;

			triProjected.p[0].x *= 0.5f * (float)ScreenWidth();
			triProjected.p[0].y *= 0.5f * (float)ScreenHeight();
			triProjected.p[1].x *= 0.5f * (float)ScreenWidth();
			triProjected.p[1].y *= 0.5f * (float)ScreenHeight();
			triProjected.p[2].x *= 0.5f * (float)ScreenWidth();
			triProjected.p[2].y *= 0.5f * (float)ScreenHeight();
			
			DrawTriangle(triProjected.p[0], triProjected.p[0].y,
					tri.p[1].x, triProjected.p[1], matProj,
					tri.p[2].x, triProjected.p[2], matProj,
					PIXEL_SOLID, FG_WHITE); {
			}
    }

    return true;
  };

private:
  mesh meshCube;
  mat4x4 matProj;

  void MultipleMatrixVector(vec3d &i, vec3d &o, mat4x4 &m)
  {
    o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
    o.x = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
    o.x = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
    float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];
    
    if (w != 0.0f)
    {
      o.x /= w; o.y /= w; o.z /= w;
    }
  }
};

#endif
// source: https://www.youtube.com/watch?v=ih20l3pJoeU&list=PL2AaJ-EqyFmoW5xYjh9n--283yhoVEMkq&index=4
