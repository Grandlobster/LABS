#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
int m;
class Polygon
{
public:
    double b[10][3];
    Polygon()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 3; j++)
                b[i][j] = 0;
    }
    Polygon(int x)
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 3; j++)
                b[i][j] = 0;
        switch (x)
        {
        case 1:
            int sx, sy;
            cout << "Enter the scaling factor for x:";
            cin >> sx;
            cout << "Enter the scaling factor for y:";
            cin >> sy;
            b[0][0] = sx;
            b[1][1] = sy;
            b[2][2] = 1;
            break;
        case 2:
            int tx, ty;
            cout << "Enter the value with which you want to translate polygon along x axis:";
            cin >> tx;
            cout << "Enter the value with which you want to translate polygon along y axis:";
            cin >> ty;
            b[0][0] = 1;
            b[1][1] = 1;
            b[2][2] = 1;
            b[2][0] = tx;
            b[2][1] = ty;
            break;
        case 3:
            double theta;
            cout << "\nEnter the angle:";
            cin >> theta;
            theta = theta * (3.14 / 180);
            b[0][0] = cos(theta);
            b[0][1] = sin(theta);
            b[1][0] = -sin(theta);
            b[1][1] = cos(theta);
            b[2][2] = 1;
            break;
        }
    }

public:
    void accept()
    {
        cout << "Enter the number of sides:";
        cin >> m;
        cout << "Enter the coordinates:";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < 2; j++)
                cin >> b[i][j];
            b[i][2] = 1;
        }
    }
    void display()
    {
        int i;
        line(0, 240, 640, 240);
        line(320, 0, 320, 480);
        for (i = 0; i < m - 1; i++)
        {
            line(b[i][0] + 320, 240 - b[i][1], b[i + 1][0] + 320, 240 - b[i + 1][1]);
        }
        line(b[i][0] + 320, 240 - b[i][1], b[0][0] + 320, 240 - b[0][1]);
    }
    Polygon operator*(Polygon t)
    {
        Polygon temp;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < 3; j++)
            {
                temp.b[i][j] = 0;
                for (int k = 0; k < m; k++)
                    temp.b[i][j] = temp.b[i][j] + b[i][k] * t.b[k][j];
                cout << temp.b[i][j];
            }
        return temp;
    }
};
int main()
{
    Polygon p;
    Polygon n;
    int choice;
    p.accept();
    int gd = DETECT, gm;
    do
    {
        cout << "\nWhat would you like to do?";
        cout << "\n1)Scale.\n2)Translate.\n3)Rotate.\n";
        cin >> choice;
        Polygon z(choice);
        n = p * z;
        initgraph(&gd, &gm, NULL);
        p.display();
        n.display();
        getch();
        closegraph();
    } while (1);
    return 0;
}