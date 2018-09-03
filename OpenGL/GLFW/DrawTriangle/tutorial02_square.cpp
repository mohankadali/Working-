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
        window = glfwCreateWindow( 1024, 768, "Tutorial 02 - Square", NULL, NULL);
        glfwMakeContextCurrent(window);

        glewExperimental = true; // Needed for core profile,glewExperimental does is allow extension entry points to be loaded even if the extension
 
        glewInit();
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

        /* VAO */

        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

        /* filling the vertex buffer */

        static const GLfloat g_vertex_buffer_data[] = { 
                1.0f, 1.0f, 1.0f,
                -1.0f, -1.0f, 1.0f,
                1.0f, -1.0f, 0.0f,
                1.0f, 1.0f, 1.0f,
                -1.0f, -1.0f, 1.0f,
                -1.0f, 1.0f, 0.0f

        };
        static const GLfloat g_color_buffer_data[] = {
                0.7f,0.8f,0.9f,        
                0.0f,1.0f,0.0f,
                0.0f,1.0f,0.0f,
                0.7f,0.8f,0.9f        
        };


        /*  Creating a buffer */

        GLuint vertexbuffer;
        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


        GLuint colorbuffer;
        glGenBuffers(1, &colorbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);



        printf("before....\n");
        GLuint programID = LoadShaders( "Square_vertex.txt", "Square_fragment.txt" );
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


                glEnableVertexAttribArray(1);
                glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
                glVertexAttribPointer(
                                1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                                3,                                // size
                                GL_FLOAT,                         // type
                                GL_FALSE,                         // normalized?
                                0,                                // stride
                                (void*)0                          // array buffer offset
                                );




                /* to make a square */
                glDrawArrays(GL_TRIANGLES, 0, 2*3); // 3 indices starting at 0 -> 1 triangle

                glDisableVertexAttribArray(0);
                glDisableVertexAttribArray(1);

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

