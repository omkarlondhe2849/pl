#include <iostream>
using namespace std;

class sparse
{
    int sp[50][3];
public:
    void accept();
    void simple_tr(sparse s1);
    void display();
    void fast_tr(sparse s1);
    void mul(sparse s1, sparse s2);
    void add(sparse s1, sparse s2);
};

void sparse::accept()
{
    int i;
    cout << "\nEnter Number Of Rows, Columns And Number of Non-Zero Elements: ";
    cin >> sp[0][0] >> sp[0][1] >> sp[0][2];
    for (i = 1; i <= sp[0][2]; i++)
    {
        cout << "Enter Row Number, Column Number And Non-Zero Element: ";
        cin >> sp[i][0] >> sp[i][1] >> sp[i][2];
    }
}

void sparse::simple_tr(sparse s1)
{
    int i, j, k = 1;
    sp[0][0] = s1.sp[0][1];
    sp[0][1] = s1.sp[0][0];
    sp[0][2] = s1.sp[0][2];
    for (i = 0; i < s1.sp[0][1]; i++)
    {
        for (j = 1; j <= s1.sp[0][2]; j++)
        {
            if (s1.sp[j][1] == i)
            {
                sp[k][0] = s1.sp[j][1];
                sp[k][1] = s1.sp[j][0];
                sp[k][2] = s1.sp[j][2];
                k++;
            }
        }
    }
}

void sparse::fast_tr(sparse s1)
{
    int *cnt = new int[s1.sp[0][1]];
    int *loc = new int[s1.sp[0][1]];
    int i, colno, index;
    for (i = 0; i < s1.sp[0][1]; i++)
        cnt[i] = 0;
    for (i = 1; i <= s1.sp[0][2]; i++)
        cnt[s1.sp[i][1]]++;
    loc[0] = 1;
    for (i = 1; i < s1.sp[0][1]; i++)
        loc[i] = loc[i - 1] + cnt[i - 1];
    for (i = 1; i <= s1.sp[0][2]; i++)
    {
        colno = s1.sp[i][1];
        index = loc[colno]++;
        sp[index][0] = s1.sp[i][1];
        sp[index][1] = s1.sp[i][0];
        sp[index][2] = s1.sp[i][2];
    }
    sp[0][0] = s1.sp[0][1];
    sp[0][1] = s1.sp[0][0];
    sp[0][2] = s1.sp[0][2];
    delete[] cnt;
    delete[] loc;
}

void sparse::mul(sparse s1, sparse s2)
{
    sparse s4;
    if (s1.sp[0][1] != s2.sp[0][0])
    {
        cout << "Cannot multiply\n";
        return;
    }
    s4.simple_tr(s2);
    int i = 1, j, k = 1, a, b, row, col, sum;
    while (i <= s1.sp[0][2])
    {
        row = s1.sp[i][0];
        j = 1;
        while (j <= s4.sp[0][2])
        {
            col = s4.sp[j][0];
            sum = 0;
            a = i;
            b = j;
            while (a <= s1.sp[0][2] && b <= s4.sp[0][2] && s1.sp[a][0] == row && s4.sp[b][0] == col)
            {
                if (s1.sp[a][1] == s4.sp[b][1])
                {
                    sum += s1.sp[a][2] * s4.sp[b][2];
                    a++;
                    b++;
                }
                else if (s1.sp[a][1] < s4.sp[b][1])
                    a++;
                else
                    b++;
            }
            if (sum != 0)
            {
                sp[k][0] = row;
                sp[k][1] = col;
                sp[k][2] = sum;
                k++;
            }
            while (j <= s4.sp[0][2] && s4.sp[j][0] == col)
                j++;
        }
        while (i <= s1.sp[0][2] && s1.sp[i][0] == row)
            i++;
    }
    sp[0][0] = s1.sp[0][0];
    sp[0][1] = s2.sp[0][1];
    sp[0][2] = k - 1;
}

void sparse::add(sparse s1, sparse s2)
{
    if (s1.sp[0][0] != s2.sp[0][0] || s1.sp[0][1] != s2.sp[0][1])
    {
        cout << "Unable To Add\n";
        return;
    }
    int i = 1, j = 1, k = 1;
    while (i <= s1.sp[0][2] && j <= s2.sp[0][2])
    {
        if (s1.sp[i][0] == s2.sp[j][0])
        {
            if (s1.sp[i][1] == s2.sp[j][1])
            {
                sp[k][0] = s1.sp[i][0];
                sp[k][1] = s1.sp[i][1];
                sp[k][2] = s1.sp[i][2] + s2.sp[j][2];
                i++;
                j++;
                k++;
            }
            else if (s1.sp[i][1] < s2.sp[j][1])
            {
                sp[k][0] = s1.sp[i][0];
                sp[k][1] = s1.sp[i][1];
                sp[k][2] = s1.sp[i][2];
                i++;
                k++;
            }
            else
            {
                sp[k][0] = s2.sp[j][0];
                sp[k][1] = s2.sp[j][1];
                sp[k][2] = s2.sp[j][2];
                j++;
                k++;
            }
        }
        else if (s1.sp[i][0] < s2.sp[j][0])
        {
            sp[k][0] = s1.sp[i][0];
            sp[k][1] = s1.sp[i][1];
            sp[k][2] = s1.sp[i][2];
            i++;
            k++;
        }
        else
        {
            sp[k][0] = s2.sp[j][0];
            sp[k][1] = s2.sp[j][1];
            sp[k][2] = s2.sp[j][2];
            j++;
            k++;
        }
    }
    while (i <= s1.sp[0][2])
    {
        sp[k][0] = s1.sp[i][0];
        sp[k][1] = s1.sp[i][1];
        sp[k][2] = s1.sp[i][2];
        i++;
        k++;
    }
    while (j <= s2.sp[0][2])
    {
        sp[k][0] = s2.sp[j][0];
        sp[k][1] = s2.sp[j][1];
        sp[k][2] = s2.sp[j][2];
        j++;
        k++;
    }
    sp[0][0] = s1.sp[0][0];
    sp[0][1] = s1.sp[0][1];
    sp[0][2] = k - 1;
}

void sparse::display()
{
    int i, n = sp[0][2];
    cout << endl << "----------------------------------------------" << endl;
    cout << "Row\tColumn\tValue";
    for (i = 1; i <= n; i++)
    {
        cout << endl << sp[i][0] << "\t" << sp[i][1] << "\t" << sp[i][2];
    }
    cout << endl << "----------------------------------------------" << endl;
}

int main()
{
    sparse s1, s2, s3;
    int choice;
    do
    {
        cout << "\n1. Simple Transpose\n2. Fast Transpose\n3. Multiplication\n4. Addition\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s1.accept();
            s3.simple_tr(s1);
            s3.display();
            break;
        case 2:
            s1.accept();
            s3.fast_tr(s1);
            s3.display();
            break;
        case 3:
            cout << "Matrix 1:\n";
            s1.accept();
            cout << "Matrix 2:\n";
            s2.accept();
            s3.mul(s1, s2);
            s3.display();
            break;
        case 4:
            cout << "Matrix 1:\n";
            s1.accept();
            cout << "Matrix 2:\n";
            s2.accept();
            s3.add(s1, s2);
            s3.display();
            break;
        case 5:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}