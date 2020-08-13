#pragma once

//For the Camera Struct
struct Vector3 
{
	float x, y, z;
	
};


// Struct that creates the 3D Camera
struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};


// Colour for Cube
struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat	x, y, z;
};
