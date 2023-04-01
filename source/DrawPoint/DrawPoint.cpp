#include <cstdio>
#include "glew/glew.h"
#include "freeglut/freeglut.h"
#include "ogldev_math_3d.h"


GLuint VBO;

void RenderSceneCallback()
{
    //
    glClear(GL_COLOR_BUFFER_BIT);

    // 激活索引0表示的顶点属性
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // 描述缓冲区，告诉后面应该如何解释缓冲区内的数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_POINTS, 0, 1);
    glDrawArrays(GL_POINTS, 1, 1);

    // 关闭索引0表示的顶点属性
    glDisableVertexAttribArray(0);
    // 交换前后缓冲
    glutSwapBuffers();
}

void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCallback);
}

void CreateVertexBuffer()
{
    // 顶点数组
    Vector3f Vertices[2];
    Vertices[0] = Vector3f(-0.5f, 0.0f, 0.0f); 
    Vertices[1] = Vector3f(0.5f, 0.0f, 0.0f); 

    // 创建一个缓冲，以VBO作为句柄 - 申请内存
    glGenBuffers(1, &VBO); 

    // 将GL_ARRAY_BUFFER的状态绑定到VBO，明确了VBO的用途 - 明确内存的用途
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    // 对内存写入数据
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1024, 768);

    glutCreateWindow("DrawPoint");

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }
    
    CreateVertexBuffer();
    InitializeGlutCallbacks();
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutMainLoop();
    return 0;
}
