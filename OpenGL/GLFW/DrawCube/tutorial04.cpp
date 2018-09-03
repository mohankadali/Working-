#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../external/glm-0.9.7.1/glm/glm.hpp"
#include "../external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"

#include "../common/shader.hpp"
#include "../common/shader.cpp"

using namespace glm;
GLFWwindow* window;

int main( void )
{
        glfwInit();

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow( 1024, 768, "Tutorial 04 - Colored Cube", NULL, NULL);
        glfwMakeContextCurrent(window);
        glewExperimental = true; // Needed for core profile
        glewInit();
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);



        // Enable depth test
        glEnable(GL_DEPTH_TEST);
        // Accept fragment if it closer to the camera than the former one
        glDepthFunc(GL_LESS); 



        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);


        glm::mat4 Projection = glm::perspective(glm::radians(60.0f), 4.0f / 3.0f, 0.1f, 100.0f);
        glm::mat4 View       = glm::lookAt(
                        glm::vec3(4,3,3), // Camera is at (4,3,-3), in World Space
                        glm::vec3(0,0,0), // and looks at the origin
                        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                        );
        //	glm::mat4 Model      = glm::mat4(1.0f);
        //	glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around






        // Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
        // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
        static const GLfloat g_vertex_buffer_data[] = { 
                -1.0f,-1.0f,-1.0f,
                -1.0f,-1.0f, 1.0f,
                -1.0f, 1.0f, 1.0f,
                 1.0f, 1.0f,-1.0f,
                -1.0f,-1.0f,-1.0f,
                -1.0f, 1.0f,-1.0f,
                 1.0f,-1.0f, 1.0f,
                -1.0f,-1.0f,-1.0f,
                 1.0f,-1.0f,-1.0f,
                 1.0f, 1.0f,-1.0f,
                 1.0f,-1.0f,-1.0f,
                -1.0f,-1.0f,-1.0f,
                -1.0f,-1.0f,-1.0f,
                -1.0f, 1.0f, 1.0f,
                -1.0f, 1.0f,-1.0f,
                 1.0f,-1.0f, 1.0f,
                -1.0f,-1.0f, 1.0f,
                -1.0f,-1.0f,-1.0f,
                -1.0f, 1.0f, 1.0f,
                -1.0f,-1.0f, 1.0f,
                 1.0f,-1.0f, 1.0f,
                 1.0f, 1.0f, 1.0f,
                 1.0f,-1.0f,-1.0f,
                 1.0f, 1.0f,-1.0f,
                 1.0f,-1.0f,-1.0f,
                 1.0f, 1.0f, 1.0f,
                 1.0f,-1.0f, 1.0f,
                 1.0f, 1.0f, 1.0f,
                 1.0f, 1.0f,-1.0f,
                -1.0f, 1.0f,-1.0f,
                 1.0f, 1.0f, 1.0f,
                -1.0f, 1.0f,-1.0f,
                -1.0f, 1.0f, 1.0f,
                 1.0f, 1.0f, 1.0f,
                -1.0f, 1.0f, 1.0f,
                 1.0f,-1.0f, 1.0f
        };

        // One color for each vertex. They were generated randomly.
        static const GLfloat g_color_buffer_data[] = { 
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f,
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                0.0f,  1.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                1.0f,  0.0f,  0.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f,
                0.0f,  0.0f,  1.0f
        };

        GLuint vertexbuffer;                            //creates vertex buffer object and store vertices in the video card 
        glGenBuffers(1, &vertexbuffer);                 //create a handle for our VBO 
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);    //Allocate space and upload the data from CPU to GPU
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data,GL_STATIC_DRAW); //it will allocate space for the VBO and fill it with the content of our vertices_position array.

        GLuint colorbuffer;
        glGenBuffers(1, &colorbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

        GLuint programID = LoadShaders("TransformVertexShader.vertexshader","ColorFragmentShader.fragmentshader"); //shader program executed in video card gpu 


        glm::mat4 Model;
        Model = glm::translate(glm::mat4(1.0f),glm::vec3(5,0,0));
        Model = glm::scale((glm::mat4(2.0f)),glm::vec3(1.0f,0.0f,0.0f));



        do{


                Model = glm::rotate(glm::mat4(2.0f),(GLfloat)glfwGetTime()*4.0f,glm::vec3(1.0f,0.0f,1.0f));
                glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around
                GLuint MatrixID = glGetUniformLocation(programID, "MVP");//Get the location of the attributes that enters in the vertex shader




                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glUseProgram(programID);
                glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);



                // 1rst attribute buffer : vertices
                glEnableVertexAttribArray(0);// Enable the attribute
                glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
                glVertexAttribPointer(
                                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                                3,                  // size
                                GL_FLOAT,           // type
                                GL_FALSE,           // normalized?
                                0,                  // stride
                                (void*)0            // array buffer offset
                                ); // Specify how the data for position can be accessed

                // 2nd attribute buffer : colors
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

                // Draw the triangle !
                glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles, in graphics pipeline it is a primitive setup

                // Swap buffers
                glfwSwapBuffers(window);
                glfwPollEvents();

        } // Check if the ESC key was pressed or the window was closed
        while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
                        glfwWindowShouldClose(window) == 0 );

        // Cleanup VBO and shader
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDeleteBuffers(1, &vertexbuffer);
        glDeleteBuffers(1, &colorbuffer);
        glDeleteProgram(programID);
        glDeleteVertexArrays(1, &VertexArrayID);

        glfwTerminate();

        return 0;
}
