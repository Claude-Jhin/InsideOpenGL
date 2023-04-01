#include "freeglut/freeglut.h"

void RenderSceneCB()
{
    // 使用背景颜色状态的值刷屏
    glClear(GL_COLOR_BUFFER_BIT);

    // 交换front和back缓冲区
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    // 初始化freeglut，并支持命令行参数
    glutInit(&argc, argv);

    // 初始化显示模式：双缓冲，RGBA颜色模式，深度缓存
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    // 设置窗口大小
    glutInitWindowSize(1024, 768);

    // 设置窗口位置（左上角坐标）
    glutInitWindowPosition(100, 100);

    // 设置窗口标题
    glutCreateWindow("Chapter1Summary");

    // 注册回调函数
    glutDisplayFunc(RenderSceneCB);

    // 设置背景颜色的值
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

    // glut主循环，执行前面注册的回调函数
    glutMainLoop();

    return 0;
}
