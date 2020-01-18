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
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        window = glfwCreateWindow( 1024, 768, "MOHAN", NULL, NULL);
        glfwMakeContextCurrent(window);
        glewExperimental = true; // Needed for core profile
        glewInit(); 
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);


        // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
        // glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 2.0f, 0.1f, 100.0f);
        // Or, for an ortho camera :
        glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

        // Camera matrix
        glm::mat4 View       = glm::lookAt(
                                glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
                                glm::vec3(0,0,0), // and looks at the origin
                                glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                );

/*
        static const GLfloat g_vertex_buffer_data[] = { 
                -1.0f, -1.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                1.0f,  -1.0f, 0.0f,
                -1.0f, -1.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                -1.0f,  1.0f, 0.0f,
                        
        };
*/
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

        GLuint vertexbuffer;
        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

        GLuint programID = LoadShaders( "SimpleTransform.vertexshader", "SingleColor.fragmentshader" );

                // Model matrix : an identity matrix (model will be at the origin)
                glm::mat4 Model;
                Model = glm::translate(glm::mat4(1.0f),glm::vec3(5,0,0));
                Model = glm::scale((glm::mat4(2.0f)),glm::vec3(1.0f,0.0f,0.0f));       
        do{
                Model = glm::rotate(glm::mat4(2.0f),(GLfloat)glfwGetTime()*5.0f,glm::vec3(1.0f,0.0f,1.0f));

                glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around

                GLuint MatrixID = glGetUniformLocation(programID, "MVP");

                
                
                glClear( GL_COLOR_BUFFER_BIT );
                glUseProgram(programID);

                // Send our transformation to the currently bound shader, 
                // in the "MVP" uniform
                glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
                glVertexAttribPointer(
                                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                                3,                  // size
                                GL_FLOAT,           // type
                                GL_FALSE,           // normalized?
                                0,                  // stride
                                (void*)0            // array buffer offset
                                );

                glDrawArrays(GL_TRIANGLES, 0, 12*3); // 3 indices starting at 0 -> 1 triangle
                glDisableVertexAttribArray(0);
                glfwSwapBuffers(window);
                glfwPollEvents();
        } // Check if the ESC key was pressed or the window was closed
        while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
                        glfwWindowShouldClose(window) == 0 );

        // Cleanup VBO and shader
        glDeleteBuffers(1, &vertexbuffer);
        glDeleteProgram(programID);
        glDeleteVertexArrays(1, &VertexArrayID);

        // Close OpenGL window and terminate GLFW
        glfwTerminate();

        return 0;
}

