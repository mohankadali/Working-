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



        /*
         * glfwWindowHint set hints for the next call glfwCreateWindow it will keep the
         * same hint for untill terminate the window
         */
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);




        window = glfwCreateWindow( 1024, 768, "Tutorial 02 - Points ", NULL, NULL);
        glfwMakeContextCurrent(window);






        /*  
         * Needed for core profile,glewExperimental does is allow 
         * extension entry points to be loaded even if the extension
         */
        glewExperimental = true;





        glewInit();
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);





        /* 
         * VAO:OpenGL stores the information about the links between the attributes and
         * the VBO in a special variable named Vertex Array Object, or VAO. Once a VAO is created
         * and binded, all the information about where the data is located is stored in the VAO.
         * This means that we need to bind a VAO before we transfer the data to a VBO or create
         * the shader program and the links between inputs/outputs from the shader program
         */
        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);






        /*
         * A Vertex Buffer Object, or VBO, is a chunk of memory managed by OpenGL,
         * basically it is a piece of the memory of your video card.
         */
        static const GLfloat g_vertex_buffer_data[] = { 
                1.0f, 1.0f,0.0f,
                -1.0f, 1.0f,0.0f,
                1.0f, -1.0f,0.0f,
                -1.0f, -1.0f,0.0f,

                1.0f, 1.0f,0.0f,
                1.0f, -1.0f,0.0f,
                -1.0f, -1.0f,0.0f,
                -1.0f, 1.0f,0.0f,

        };




        /*
         * vertexbuffer: Create a Vector Buffer Object that will store the vertices on video memory
         * glGenBuffers: generate buffer object names, 1 means number of buffer object names
         * glBindBuffer: bind a named buffer object 
         * glBufferData: creates and initializes a buffer object's data store. 
         */
        GLuint vertexbuffer;
        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);




        /* 
         * A vertex shader is executed for every vertex in a VBO, his role is to, potentially, apply
         * various transformations on the vertices position attribute and pass through other
         * attributes like color, texture coordinates etc … It is the programmer’s responsibility to
         * write a vertex shader for every OpenGL based application

         * The fragment shader, also the programmer’s responsibility, can potentially determine the
         * fragment final color, discard some fragments, or use texture mapping.
         * After the fragment shader, the color of a fragment can potentially be further modified if
         * the depth and stencil tests are enabled, or if blending was enabled.
         */
        GLuint programID = LoadShaders( "Points_vertex.txt", "Points_fragment.txt" );




        do{
                glClear( GL_COLOR_BUFFER_BIT );



                /* shader program is used in the loop*/
                glUseProgram(programID);




                /* 
                 * glEnableVertexAttribArray:  Enable or disable a generic vertex attribute array 
                 * glVertexAttribPointer: define an array of generic vertex attribute data
                */
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




                glDrawArrays(GL_LINES, 0, 8);  
//                glDrawArrays(GL_POINTS, 0, 4*2); // no need of buffer values for a point  

                glDisableVertexAttribArray(0);

                glfwSwapBuffers(window);
                glfwPollEvents();

        }while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );
        // Cleanup VBO
        glDeleteBuffers(1, &vertexbuffer);
        glDeleteVertexArrays(1, &VertexArrayID);
        glDeleteProgram(programID);

        glfwTerminate();

        return 0;
}

