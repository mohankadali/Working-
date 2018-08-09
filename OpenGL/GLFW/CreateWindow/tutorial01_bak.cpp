/* include the standard header */
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
GLFWwindow* window;
int main()
{
        glfwInit();                                                     // This function initializes the GLFW library. 
        window = glfwCreateWindow(1024,820,"MOHAN",NULL,NULL);   

        glfwMakeContextCurrent(window);                                 /* Basically all drawing happens in the current context.
                                                                            If you make a different context current, then all drawing will now
                                                                            happen in that context.
                                                                        */

        glewInit();                                                     /* The OpenGL Extension Wrangler Library (GLEW) is a cross-platform open-source
                                                                          C/C++ extension loading library. GLEW provides efficient run-time mechanisms
                                                                          for determining which OpenGL extensions are supported on the target platform.
                                                                          OpenGL core and extension functionality is exposed in a single header file.
                                                                        */

        glfwSetInputMode (window,GLFW_STICKY_KEYS,GL_TRUE);             /* This function sets an input mode option for the specified window.
                                                                           The mode must be one of GLFW_CURSOR, GLFW_STICKY_KEYS or
                                                                           GLFW_STICKY_MOUSE_BUTTONS.
                                                                        */

        glClearColor(1.0f,1.0f,1.0f,0.0f);

        do
        {
                glClear(GL_COLOR_BUFFER_BIT);
                glfwSwapBuffers(window);                                /* This function
                                                                           swaps the front and back buffers of the specified window when rendering with OpenGL or
                                                                           OpenGL ES. If the swap interval is greater than zero, the GPU driver waits the specified
                                                                           number of screen updates before swapping the buffers.
                                                                         */
                glfwPollEvents();

        }while( glfwGetKey(window,GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

        glfwTerminate();

        return 0;
}





