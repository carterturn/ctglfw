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

#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

std::string glfwTextbox(std::string initial);
void addtext(GLFWwindow * window, unsigned int codepoint);
