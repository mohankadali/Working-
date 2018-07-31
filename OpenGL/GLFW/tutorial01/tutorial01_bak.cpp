/* include the standard header */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
GLFWwindow* window;
int main()
{

        glfwInit();

        //      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        //      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

        window = glfwCreateWindow(1024,820,"MOHAN",NULL,NULL);

        glfwMakeContextCurrent(window);

        glewInit();

        glfwSetInputMode (window,GLFW_STICKY_KEYS,GL_TRUE);

        glClearColor(1.0f,0.0f,0.0f,0.0f);

        do
        {
                glClear(GL_COLOR_BUFFER_BIT);
                glfwSwapBuffers(window);
                glfwPollEvents();

        }while( glfwGetKey(window,GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );
        glfwTerminate();
        return 0;
}
