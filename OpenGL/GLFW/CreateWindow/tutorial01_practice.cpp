#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow* window;

int main()
{

        glfwInit();

        window = glfwCreateWindow(800,600,"NEW WINDOW",NULL,NULL);

        glfwMakeContextCurrent(window);

        glfwSetInputMode(window,GLFW_STICKY_MOUSE_BUTTONS,GL_TRUE);

        glClearColor(1.0f,1.0f,1.0f,0.0);

        do{

                glClear(GL_COLOR_BUFFER_BIT);

                glfwSwapBuffers(window);

                glfwPollEvents();

        }while(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) != (GLFW_PRESS && glfwWindowShouldClose(window)==0));

        glfwTerminate();
        return 0;
}
