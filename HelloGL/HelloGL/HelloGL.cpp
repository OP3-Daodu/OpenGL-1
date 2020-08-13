#include "HelloGL.h"



HelloGL::HelloGL(int argc, char* argv[])
{
	
	//rotation = 0.0f;
	
	GLUTCallbacks::Init(this);
	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE); // | GLUT_DEPTH

	glutInitWindowSize(800, 800);
	
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);

	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	//changing the Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	// Set the correct perspective.
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);

	//enabling back face-culling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Z Buffering
	//glEnable(GL_DEPTH_TEST);


	//initialises the 3D Camera Struct
	camera = new Camera();

	//
	for (int i = 0; i < 200; i++)
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);

	}




	glutMainLoop();


}






void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); // GL_DEPTH_BUFFER_BIT this clears the scene
	
	//Draws Cube 
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Draw();

	}
	

	glFlush(); //flushes the scene drawn to the graphics card

	glutSwapBuffers();

}







void HelloGL::Update()
{
	
	glLoadIdentity();
	//Loads struct camera data and uses it to 
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);


	
	glutPostRedisplay();
	//rotation += 0.5f;

	




}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	
}





HelloGL::~HelloGL(void)
{
	delete camera;

	

}