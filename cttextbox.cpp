/*
  Copyright 2015 Carter Turnbaugh

  This file is part of Terca C++ GLFW Wrapper.

  Terca C++ GLFW Wrapper is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Terca C++ GLFW Wrapper is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Terca C++ GLFW Wrapper.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "cttextbox.h"
#include <unistd.h>
#include <cmath>
#include <FTGL/ftgl.h>

std::string text;
bool done;

void addtext(GLFWwindow * window, unsigned int codepoint){
	text += (char) codepoint;
}

void checkkeys(GLFWwindow * window, int key, int scancode, int action, int mods){
	if(action == GLFW_PRESS){
		if(key == GLFW_KEY_BACKSPACE){
			text = text.substr(0, text.length()-1);
		}
		else if(key == GLFW_KEY_ENTER){
			done = true;
		}
	}
}

std::string glfwTextbox(std::string initial){
	text = initial;
	done = false;
	GLFWwindow * window = glfwCreateWindow(initial.length() * 10, 60, "Enter Text", NULL, NULL);

	if(!window){
		return "ERROR: Unable to create window\n";
	}

	glfwMakeContextCurrent(window);
	glfwSetCharCallback(window, addtext);
	glfwSetKeyCallback(window, checkkeys);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	FTGLPixmapFont *font = new FTGLPixmapFont("font.ttf");

	if(font->Error()){
		return "ERROR: unable to find font\n";
	}

	font->FaceSize(24);

	while(!glfwWindowShouldClose(window) && !done){
		glClear(GL_COLOR_BUFFER_BIT);
		
		glColor3f(0.5f, 0.5f, 0.5f);

		glRasterPos2f(-1, 0);

		std::string rendertext = " " + text;
		font->Render(rendertext.c_str());

		glfwSetWindowSize(window, fmax(text.length() * 12, 60), 60);

		glfwSwapBuffers(window);
		glfwPollEvents();
		usleep(1000);
	}

	delete(font);

	glfwDestroyWindow(window);

	return text;
}
