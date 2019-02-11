#include "stdafx.h"
#include <stdio.h>
#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include<iostream>

using namespace std;

void dibujar();
void actualizar();
void dibujarRana();
void dibujarVehiculos();
void dibujarTroncos();
void dibujarMapa();

int main()
{
	//Declaramos apuntador de ventana
	GLFWwindow *window;

	//Si no se pudo iniciar glfw
	//terminamos ejecución 
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	
	//Si se pudo inciar GLFW
	//Entonces inicializamos la ventana

	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	//Si no podemos iniciar la ventana 
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecer el contexto
	glfwMakeContextCurrent(window);


	//Una vez establecido el contexto
	//Activamos fnciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK)
	{
		cout << glewGetErrorString(errorGlew);

	}


	const GLubyte *versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: "
		<< versionGL;



	//ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window))
	{
		glViewport(0, 0,1024, 768);
		//Establecer el color de orrado
		glClearColor(0.5, 0.4, 1, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}


void dibujar()
{
	dibujarMapa();
	dibujarVehiculos();
	// dibujarTroncos();
	dibujarRana();
}

void actualizar() 
{

}

void dibujarRana()
{
	glPushMatrix();
		glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex3f(-.0625f, -.875f, 0.0f);
			glVertex3f(-.0625f, -1.0f, 0.0f);
			glVertex3f(.0625f, -1.0, 0.0f);
			glVertex3f(.0625f, -.875f, 0.0f);
		glEnd();
	glPopMatrix();
}

void dibujarVehiculos()
{
	//Inicio de la Matriz
	glPushMatrix();

		// Carro Rosa 1er Carril
		glBegin(GL_QUADS);
			glColor3f(1.0f, 0.45f, 0.796f);
			glVertex3f(-.8125f, -.875f, 0.0f);
			glVertex3f(-.8125f, -.75f, 0.0f);
			glVertex3f(-.9375f, -.75f, 0.0f);
			glVertex3f(-.9375f, -.875f, 0.0f);
		glEnd();

		// Camión Morado 2do Carril
		glBegin(GL_QUADS);
			glColor3f(0.8f, 0.0f, 0.8f);
			glVertex3f(.6875f, -.75f, 0.0f);
			glVertex3f(.5625f, -.75f, 0.0f);
			glVertex3f(.5625f, -.625f, 0.0f);
			glVertex3f(.6875f, -.625f, 0.0f);
		glEnd();

		// Camión Amarillo 3er Carril
		glBegin(GL_QUADS);
			glColor3f(1.0f, 0.7f, 0.2f);
			glVertex3f(-.3125f, -.625f, 0.0f);
			glVertex3f(-.5625f, -.625f, 0.0f);
			glVertex3f(-.5625f, -.5f, 0.0f);
			glVertex3f(-.3125f, -.5f, 0.0f);
		glEnd();

	// Fin de la Matriz
	glPopMatrix();
}

void dibujarTroncos()
{
	// Inicio de la Matriz
	glPushMatrix();

	// Tronco
		glBegin(GL_QUADS);
			glColor3f(0.737f, 0.5607f, 0.5607f);
			glVertex3f(-.2f, -.75f, 0.0f);
			glVertex3f(-.75f, -.75f, 0.0f);
			glVertex3f(-.75f, -.875f, 0.0f);
			glVertex3f(-.2f, -.875f, 0.0f);
		glEnd();

	// Fin de la Matriz
	glPopMatrix();
}

void dibujarMapa()
{
	// Banqueta
	glBegin(GL_QUADS);
		glColor3f(.8f, .8f, .8f);
		glVertex3f(-1.0f, -.875f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0, 0.0f);
		glVertex3f(1.0f, -.875f, 0.0f);
	glEnd();

	// Banqueta Central
	glBegin(GL_QUADS);
		glColor3f(.8f, .8f, .8f);
		glVertex3f(-1.0f, -.125, 0.0f);
		glVertex3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, -.125, 0.0f);
	glEnd();

	// Carriles
	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, -.875f, 0.0f);
		glVertex3f(-1.0f, -.125f, 0.0f);
		glVertex3f(1.0f, -.125f, 0.0f);
		glVertex3f(1.0f, -.875f, 0.0f);
	glEnd();

	// Líneas de los Carriles
	glPushAttrib(GL_ENABLE_BIT);
	glLineStipple(2, 0x00FF);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	for (float c = -.75; c < -.125; c += .125)
	{
		glColor3f(1.0f, 0.7f, 0.2f);
		glVertex3f(-1, c, -.5);
		glVertex3f(1, c, -.5);
	}
	glEnd();
	glPopAttrib();

	// Río
	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.6f, 0.8f);
		glVertex3f(-1.0f, -0.0f, 0.0f);
		glVertex3f(-1.0f, .75, 0.0f);
		glVertex3f(1.0f, .75, 0.0f);
		glVertex3f(1.0f, -0.0f, 0.0f);
	glEnd();

	// Cesped
	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.85f, 0.4f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, .75, 0.0f);
		glVertex3f(1.0f, .75, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();

	// Cuadro 1
	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.6f, 0.8f);

		glVertex3f(-.0625f, .825f, 0.0f);
		glVertex3f(-.0625f, .75f, 0.0f);
		glVertex3f(.0625f, .75f, 0.0f);
		glVertex3f(.0625f, .825f, 0.0f);
	glEnd();
}