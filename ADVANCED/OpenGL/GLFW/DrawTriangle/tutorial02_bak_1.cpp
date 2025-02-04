#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../common/shader.hpp"
#include "../common/shader.cpp"

GLFWwindow* window;

int main( void )
{
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        window = glfwCreateWindow( 1024, 768, "Tutorial 02 - Red triangle", NULL, NULL);
        glfwMakeContextCurrent(window);
        glewExperimental = true; // Needed for core profile,glewExperimental does is allow extension entry points to be loaded even if the extension
        glewInit();
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        /* VAO */

        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

        /* filling the vertex buffer */

        static const GLfloat g_vertex_buffer_data[] = { 
                1.0f, 1.0f, 1.0f,
                -1.0f, 1.0f, 0.0f,
                1.0f, -1.0f, 0.0f,
                -1.0f, -1.0f, 1.0f,

                1.0f, 1.0f, 1.0f,
                1.0f, -1.0f, 0.0f,
                -1.0f, -1.0f, 1.0f,
                -1.0f, 1.0f, 0.0f,

        };

        /*  Creating a buffer */

        GLuint vertexbuffer;
        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);



        printf("before....\n");
        GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
        printf("after....\n");

        do{
                glClear( GL_COLOR_BUFFER_BIT );

                glUseProgram(programID);

                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
                glVertexAttribPointer(
                                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                                3,                  // size
                                GL_FLOAT,           // type
                                GL_FALSE,           // normalized?
                                0,                  // stride
                                (void*)0            // array buffer offset
                                );


  //              	glDrawArrays(GL_LINES, 0, 8);  
                	glDrawArrays(GL_POINTS, 0, 8); // no need of buffer values for a point  


                glDisableVertexAttribArray(0);

                glfwSwapBuffers(window);
                glfwPollEvents();

        } // Check if the ESC key was pressed or the window was closed
        while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
                        glfwWindowShouldClose(window) == 0 );

        // Cleanup VBO
        glDeleteBuffers(1, &vertexbuffer);
        glDeleteVertexArrays(1, &VertexArrayID);
        glDeleteProgram(programID);

        // Close OpenGL window and terminate GLFW
        glfwTerminate();

        return 0;
}

