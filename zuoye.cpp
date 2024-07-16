#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct student {
    char username[15];
    char password[15];
    char name[15];
    char numb[8]; //借阅证号
    char gender[6];
    int age;
};
struct admin {
    char username[15];
    char password[15];
};
struct book {
    char name[15];

    char ibsn[18];
    char author[14]; // 作者
    char publish[15]; // 出版社
    double price;
    bool status = 0;
};
struct record {
    char user[15];
    char book[15];
    int time1;
    int time2;

};
vector<admin>adminlist;
vector<student>stlist;
vector<book>booklist;
vector<record>relist;
void whh() { cout << "\n输入换行符继续" << endl;   getchar(); while (char cc = getchar()) { if (cc == '\n') break; }; }
void readadmin();
void writeadmin();
void readst();
void readbook();
void writest();
void writebook();
void writerecord();
void readrecord();
void Login();
void Register();
bool islogin = 0;
bool isadmin = 0;
void stmenu();
void adminmenu();
void adduser();
void showuser();
void deleteuser();
void finduser();
void sortuser();
void addbook();
void deletebook();

void findbook();
void sortbook();
void modifyuser();
void modifybook();
void addrecord();
void deleterecord();
void modifyrecord();
void findrecord();
void sortrecord();
void logout();
void myaccount();
void showbook();
void showrecord();


int main() {
    readadmin();
    readbook();
    readst();
    readrecord();
    while (!islogin)
    {
        cout << "*---------------------------------------------*\n*------------1：登陆\n*------------2：注册\n*---------------------------------------------*\n请输入选择：";
        int a = 0;
        cin >> a;
        if (a == 1) {
            Login();
        }
        else if (a == 2) {
            Register();
        }
    }
    while (1)
        if (isadmin) {
            adminmenu();
            int n;
            cin >> n;
            switch (n) {
            case 1:adduser(); break;
            case 2:deleteuser(); break;
            case 3:modifyuser();  break;
            case 4:finduser(); break;
            case 5:sortuser(); break;
            case 6:addbook(); break;
            case 7:deletebook(); break;
            case 8:modifybook(); break;
            case 9:findbook(); break;
            case 10:sortbook(); break;
            case 11:addrecord(); break;
            case 12:deleterecord(); break;
            case 13:modifyrecord(); break;
            case 14:findrecord(); break;
            case 15:sortrecord(); break;
            case 0: return; break;
            }
        }
        else {
            stmenu();
            int n;
            cin >> n;
            switch (n) {
            case 1:findbook();
                break;
            case 2:sortbook();
                break;
            case 3:addrecord();
                break;
            case 4:modifyrecord();
                break;
            case 5:findrecord();
                break;
            case 6:
                sortrecord();
                break;
            }
        }
    cout << "\ngood";
    return 0;
}
void readadmin() {
    FILE* fp = fopen("Admin.txt", "r");
    if (fp == NULL) {
        return;
    }
    admin a;
    while (fscanf(fp, "%s%s", a.username, a.password) != EOF) {
        adminlist.push_back(a);
    }
    fclose(fp);
}
void writeadmin() {
    FILE* fp = fopen("Admin.txt", "w+");
    for (auto i : adminlist) {
        fprintf(fp, "%s %s\n", i.username, i.password);

    }
    fclose(fp);
}
void readst() {
    FILE* fp = fopen("St.txt", "r");
    if (fp == NULL) {
        return;
    }
    student a;
    while (fscanf(fp, "%s%s%s%s%s%d", a.username, a.password, a.name, a.gender, &a.numb, &a.age) != EOF) {
        stlist.push_back(a);
    }
    fclose(fp);
}
void readbook() {
    FILE* fp = fopen("Book.txt", "r");
    if (fp == NULL) {
        return;
    }
    book a;
    while (fscanf(fp, "%s%s%s%s%lf%d", a.name, a.ibsn, a.author, a.publish, &a.price, &a.status) != EOF) {
        booklist.push_back(a);
    }
    fclose(fp);
}
void writebook() {
    FILE* fp = fopen("Book.txt", "w+");
    for (auto i : booklist) {
        fprintf(fp, "%s %s %s %s %lf %d\n", i.name, i.ibsn, i.author, i.publish, i.price, i.status);

    }
    fclose(fp);
}
void writest() {
    FILE* fp = fopen("St.txt", "w+");

    for (auto i : stlist) {
        fprintf(fp, "%s %s %s %s %s %d\n", i.username, i.password, i.name, i.gender, i.numb, i.age);

    }
    fclose(fp);
}
void readrecord() {
    FILE* fp = fopen("Record.txt", "r");
    if (fp == NULL) {
        return;
    }
    record a;
    while (fscanf(fp, "%s%s%d%d", a.user, a.book, &a.time1, &a.time2) != EOF) {
        relist.push_back(a);
    }
    fclose(fp);
}
void writerecord() {
    FILE* fp = fopen("Record.txt", "w+");

    for (auto i : relist) {
        fprintf(fp, "%s %s %d %d  \n", i.user, i.book, i.time1, i.time2);

    }
    fclose(fp);
}
void Login() {

    while (!islogin)
    {
        char username[15];
        char password[15];
        cout << "请输入账号：";
        cin >> username;
        cout << "请输入密码：";
        cin >> password;
        for (auto i : adminlist) {
            if ((!strcmp(i.password, password)) && (!strcmp(i.username, username))) {
                islogin = 1;
                isadmin = 1;
                break;
            }
            if (!islogin) {
                for (auto i : stlist) {
                    if ((!strcmp(i.password, password)) && (!strcmp(i.username, username))) {
                        islogin = 1;
                        break;
                    }
                }

            }
        }
        if (!islogin) {
            cout << "登录失败" << endl;
            cout << "输入 0 返回" << endl;
            cout << "输入 1 继续" << endl;
            int b;
            cin >> b;
            if (!b) {
                return;
            }

        }
    }

}
void Register() {
    bool flag = 0;
    while (flag == 0) {
        flag = 1;
        cout << "*---------------------------------------------*\n*------------0:返回 \n";
        cout << "*------------1:注册管理员 \n";
        cout << "*------------2:注册用户 \n";
        cout << "*---------------------------------------------*\n请输入选择：";
        int slect = 0;
        cin >> slect;

        if (slect == 1) {
            admin a;
            cout << "请输入账号：";
            cin >> a.username;

            for (auto i : adminlist) {
                if (!strcmp(a.username, i.username))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "注册失败,用户名重复" << endl;
                continue;
            }
            cout << "请输入密码：";
            cin >> a.password;
            if (flag)
            {
                isadmin = 1;
                adminlist.push_back(a);
                writeadmin();
            }

        }
        else if (slect == 2) {
            student a;
            cout << "请输入账号：";
            cin >> a.username;

            for (auto i : stlist) {
                if (!strcmp(a.username, i.username))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "注册失败,用户名重复" << endl;
                continue;
            }
            cout << "请输入密码：";
            cin >> a.password;
            cout << "请输入姓名 ：";

            cin >> a.name;
            cout << "请输入性别 ：";

            cin >> a.gender;
            cout << "请输入年龄 ：";

            cin >> a.age;
            cout << "请输入借阅证号 ：";
            cin >> a.numb;
            if (flag)
            {
                stlist.push_back(a);
                writest();
            }

        }
        else if (slect == 0)  return;
    }
    if (flag)
        islogin = 1;
    return;
}
void adminmenu() {

    cout << "*------------------主菜单---------------------*\n";
    cout << "*-------------1 :添加用户\n";
    cout << "*-------------2 :删除用户\n";
    cout << "*-------------3 :修改用户\n";
    cout << "*-------------4 :查找用户\n";
    cout << "*-------------5 :排序用户\n";
    cout << "*-------------6 :添加图书\n";
    cout << "*-------------7 :删除图书\n";
    cout << "*-------------8 :修改图书\n";
    cout << "*-------------9 :查找图书\n";
    cout << "*-------------10 :排序图书\n";
    cout << "*-------------11 :添加借阅记录\n";
    cout << "*-------------12 :删除借阅记录\n";
    cout << "*-------------13 :修改借阅记录\n";
    cout << "*-------------14 :查找借阅记录\n";
    cout << "*-------------15 :排序借阅记录\n";
    cout << "*-------------0:退出\n";

    cout << "*---------------------------------------------*\n";
    cout << "请输入选择：";
}
void stmenu() {

    cout << "*------------------主菜单---------------------*\n";
    cout << "*-------------1 :查找图书\n";
    cout << "*-------------2 :排序图书\n";
    cout << "*-------------3 :添加借阅记录\n";
    cout << "*-------------4 :修改借阅记录\n";
    cout << "*-------------5 :查找借阅记录\n";
    cout << "*-------------6 :排序借阅记录\n";
    cout << "*-------------0:退出\n";
    cout << "*------------(-1):登出\n";
    cout << "*------------(-2):我的\n";
    cout << "*---------------------------------------------*\n";
    cout << "请输入选择：";
}
void adduser() {
    bool flag = 0;
    while (flag == 0) {
        flag = 1;
        cout << "*---------------------------------------------*\n*------------0:返回 \n";
        cout << "*------------1:添加管理员 \n";
        cout << "*------------2:添加用户 \n";
        cout << "*---------------------------------------------*\n请输入选择：";
        int slect = 0;
        cin >> slect;

        if (slect == 1) {
            admin a;
            cout << "请输入账号：";
            cin >> a.username;

            for (auto i : adminlist) {
                if (!strcmp(a.username, i.username))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "添加失败,用户名重复" << endl;
                continue;
            }
            cout << "请输入密码：";
            cin >> a.password;
            if (flag)
            {
                isadmin = 1;
                adminlist.push_back(a);
                writeadmin();
            }

        }
        else if (slect == 2) {
            student a;
            cout << "请输入账号：";
            cin >> a.username;
            for (auto i : stlist) {
                if (!strcmp(a.username, i.username))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "添加失败,用户名重复" << endl;
                continue;
            }
            cout << "请输入密码：";
            cin >> a.password;
            cout << "请输入姓名 ：";

            cin >> a.name;
            cout << "请输入性别 ：";

            cin >> a.gender;
            cout << "请输入年龄 ：";

            cin >> a.age;
            cout << "请输入借阅证号 ：";
            cin >> a.numb;

            if (flag)
            {
                stlist.push_back(a);
                writest();
            }
        }
        else if (slect == 0)  return;
    }

    return;
}
void showuser() {
    int count = 0;
    printf("\n%-5s%-15s%-15s%-15s%-8s%-10s%-18s\n\n", "序号", "用户名", "密码", "姓名", "性别", "年龄", "地址", "借阅证号");
    for (int i = 0; i < adminlist.size(); i++)
    {
        printf("%-5d%-15s%-15s%-15s%-8s%-10s%-18s \n\n", i + 1, adminlist[i].username, adminlist[i].password, "管理员"
            , "无"
            , "无"
            , "无"
        );
        count++;
    }
    for (int i = 0; i < stlist.size(); i++)
    {
        printf("%-5d%-15s%-15s%-15s%-8s%-10d%-18s \n\n", i + 1 + adminlist.size(), stlist[i].username, stlist[i].password, stlist[i].name
            , stlist[i].gender
            , stlist[i].age
            , stlist[i].numb
        );
        count++;
    }
    cout << "      共" << count << "条结果\n";

    return;

}
void showst() {
    int count = 0;
    printf("\n%-5s%-15s%-15s%-15s%-8s%-10s%-18s\n\n", "序号", "用户名", "密码", "姓名", "性别", "年龄", "地址", "借阅证号");

    for (int i = 0; i < stlist.size(); i++)
    {
        printf("%-5d%-15s%-15s%-15s%-8s%-10d%-18s \n\n", i + 1, stlist[i].username, stlist[i].password, stlist[i].name
            , stlist[i].gender
            , stlist[i].age
            , stlist[i].numb
        );
        count++;
    }
    cout << "      共" << count << "条结果\n";
    return;
}
void deleteuser() {
    while (1)
    {
        showuser();
        int n;

        cout << "输入序号,删除你想删除的账号或者输入0返回" << endl;
        cin >> n;
        if (!n)
            return;
        n--;
        if (n >= 0 && n < stlist.size() + adminlist.size()) {
            if (n >= adminlist.size())
            {
                n = n - adminlist.size();
                stlist.erase(stlist.begin() + n);
            }
            else {
                adminlist.erase(adminlist.begin() + n);
            }
            cout << "删除成功" << endl;
            writeadmin();
            writest();
        }
        else {
            cout << "您输入的序号不在此列" << endl;
        }


    }
    return;
}
void finduser() {
    int select = -1;
    while (1) {
        int count = 0;

        char conCharArr[40];


        if (select == 0)
        {
            writest();
            return;
        }
        if (select > -1 && select <= 4) {
            if (select == 1 || select == 2 || select == 3 || select == 4) {
                cout << "请输入筛选条件：";
                cin >> conCharArr;
            }
        }
        if (select == 5)
        {
            select = -1;
            stlist.clear();
            readst();
        }
        printf("\n%-5s%-15s%-15s%-15s%-8s%-10s%-18s\n\n", "序号", "用户名", "密码", "姓名", "性别", "年龄", "地址", "借阅证号");
        for (int i = 0; i < stlist.size(); i++)
            if (select == -1
                || select == 1 && strstr(stlist[i].username, conCharArr) //根据用户名,模糊查询
                || select == 2 && strstr(stlist[i].name, conCharArr) //根据姓名,模糊查询
                || select == 3 && strstr(stlist[i].gender, conCharArr) //根据性别,模糊查询
                || select == 4 && strstr(stlist[i].numb, conCharArr) //根据借阅证号,模糊查询
                ) {

                printf("%-5d%-15s%-15s%-15s%-8s%-10d%-18s \n\n", (++count), stlist[i].username, stlist[i].password, stlist[i].name
                    , stlist[i].gender
                    , stlist[i].age
                    , stlist[i].numb);


            }
            else stlist.erase(stlist.begin() + (i--));



        cout << "      共" << count << "条结果\n";




        cout << "【筛选器：你可以在以上结果的基础上，进行以下条件筛选】\n";
        cout << "0：退出\n";
        cout << "1：按 用户名 筛选\n";
        cout << "2：按 姓名 筛选\n";
        cout << "3：按 性别 筛选\n";
        cout << "4：按 借阅证号 筛选\n";
        cout << "5：刷新\n";
        cout << "请输入选择：";

        cin >> select;
    }
    readst();
    return;
}

void sortuser() {
    while (1)
    {
        int select, i, j;
        int n = stlist.size();

        cout << "1：按 用户名 排序\n";
        cout << "2：按 密码 排序\n";
        cout << "3：按 姓名 排序\n";
        cout << "4：按 性别 排序\n";
        cout << "5：按 年龄 排序\n";
        cout << "6：按 借阅证号 排序\n";
        cout << "0：退出\n";
        cout << "请输入选择：";
        cin >> select;
        if (select == 0)
        {
            writest();
            return;
        }

        for (i = 0; i < n - 1; i++)
        {
            int max1 = 0;

            for (j = i + 1; j < n; j++)
            {
                if (0
                    || select == 1 && strcmp(stlist[j].username, stlist[i].username) > 0
                    || select == 2 && strcmp(stlist[j].password, stlist[i].password) > 0
                    || select == 3 && strcmp(stlist[j].name, stlist[i].name) > 0
                    || select == 4 && strcmp(stlist[j].gender, stlist[i].gender) > 0
                    || select == 5 && stlist[j].age - stlist[i].age > 0
                    || select == 6 && strcmp(stlist[j].numb, stlist[i].numb) > 0

                    ) {

                }
                else  swap(stlist[i], stlist[j]);


            }

        }
        int count = 0;
        printf("\n%-5s%-15s%-15s%-15s%-8s%-10s%-18s\n\n", "序号", "用户名", "密码", "姓名", "性别", "年龄", "地址", "借阅证号");

        for (int i = 0; i < stlist.size(); i++)
        {
            printf("%-5d%-15s%-15s%-15s%-8s%-10d%-18s \n\n", i + 1, stlist[i].username, stlist[i].password, stlist[i].name
                , stlist[i].gender
                , stlist[i].age
                , stlist[i].numb
            );
            count++;
        }
        cout << "      共" << count << "条结果\n";
    }
}
void modifyuser() {
    showst();
    cout << "输入对应序号修改此用户" << endl;
    int i;
    int flag = 1;
    cin >> i;
    i--;
    char a[15];
    cout << "请输入用户名 ：";
    cin >> a;
    for (auto b : stlist) {

        if (!strcmp(a, b.username)) {

            flag = 0;
            break;
        }
    }
    if (flag)
    {
        strcpy(stlist[i].username, a);
        cout << "请输入密码 ：";
        cin >> stlist[i].password;
        cout << "请输入姓名 ：";
        cin >> stlist[i].name;


        cout << "请输入性别 ：";
        cin >> stlist[i].gender;
        cout << "请输入年龄 ：";
        cin >> stlist[i].age;

        cout << "请输入借阅证号 ：";
        cin >> stlist[i].numb;
        writest();
        cout << "                       修改成功" << endl;
    }
    else cout << "         修改失败，用户名重复 " << endl;
    whh();
    return;
}
void addbook() {


    bool flag = 0;
    while (flag == 0) {
        flag = 1;
        book a;
        cout << "\n请输入图书名 ：";
        cin >> a.name;
        for (auto i : booklist)
            if (!strcmp(a.name, i.name)) {
                flag = 0;
            }
        if (flag == 0) {
            cout << "添加失败，图书名已存在" << endl;
            whh();
            continue;
        }
        else {
            cout << "请输入ISBN ：";

            cin >> a.ibsn;
            for (auto i : booklist)
                if (!strcmp(a.ibsn, i.ibsn)) {
                    flag = 0;
                }
            if (flag == 0) {
                cout << "添加失败，IBSN号已存在" << endl;
                whh();
                continue;
            }
            cout << "请输入作者 ：";
            cin >> a.author;
            cout << "请输入出版社 ：";
            cin >> a.publish;
            cout << "请输入价格 ：";
            cin >> a.price;
            booklist.push_back(a);
            writebook();
        }
    }
    return;

}
void addrecord() {



    int flag = 0;
    while (flag == 0) {
        flag = 0;
        record a;
        cout << "请输入用户 ：";
        cin >> a.user;
        for (auto i : stlist)
            if (!strcmp(a.user, i.username)) {
                flag = 1;
                break;
            }
        if (flag == 0) {
            cout << "用户不存在并且不能使用管理员账号" << endl;
            cout << "输入0返回继续";
            ;
            int l;
            cin >> l;
            if (!l)
                return;

            continue;
        }
        else {
            cout << "请输入图书 ：";
            flag = 0;
            cin >> a.book;
            if (!booklist.empty())
                for (auto i = booklist.begin(); i < booklist.end(); i++)
                    if (!strcmp(a.book, (*i).name)) {
                        flag = 1;
                        if ((*i).status == 1)
                        {
                            cout << "图书已借出" << endl;
                            cout << "输入0返回继续";
                            ;
                            int l;
                            cin >> l;
                            if (!l)
                                return;
                            flag = -1;
                        }
                        (*i).status = 1;//借阅状态
                    }
            if (flag == -1) {
                continue;
            }
            if (flag == 0) {
                cout << "图书不存在" << endl;
                cout << "输入0返回继续";
                ;
                int l;
                cin >> l;
                if (!l)
                    return;
                continue;
            }
            cout << "请输入借书时间 ：";
            cin >> a.time1;
            cout << "请输入还书时间 ：";
            cin >> a.time2;
            relist.push_back(a);
            writerecord();
        }
    }
    return;

}
void showbook() {
    printf("\n%-5s%-15s%-18s%-14s%-15s%-12s\n\n", "序号", "图书名", "ISBN", "作者", "出版社", "价格");

    int count = 0, i;
    double priceSum = 0;
    for (i = 0; i < booklist.size(); i++)
    {

        printf("%-5d%-15s%-18s%-14s%-15s%-12lf \n\n", i + 1
            , booklist[i].name

            , booklist[i].ibsn
            , booklist[i].author
            , booklist[i].publish
            , booklist[i].price
        );
        count++;
    }
    cout << "共" << count << "条结果\n";
}
void showrecord() {
    printf("\n%-5s%-15s%-15s%-10s%\n\n", "序号", "用户", "图书", "借书时间", "还书时间");

    int count = 0, i;
    for (int i = 0; i < relist.size(); i++)
    {
        printf("%-5d%-15s%-15s%-10d% \n\n", i + 1
            , relist[i].user
            , relist[i].book
            , relist[i].time1
            , relist[i].time2

        );
        count++;
    }
    cout << "共" << count << "条结果\n";

}
void deletebook() {
    while (1)
    {
        showbook();
        int n;

        cout << "输入序号,删除你想删除的书籍或者输入0返回" << endl;
        cin >> n;
        if (!n)
            return;
        n--;
        if (n >= 0 && n < booklist.size()) {

            booklist.erase(booklist.begin() + n);

            cout << "删除成功" << endl;
            writebook();

        }
        else {
            cout << "您输入的序号不在此列" << endl;
            whh();
        }


    }
    return;
}
void deleterecord() {
    while (1)
    {
        showrecord();
        int n;

        cout << "输入序号,删除你想删除的记录或者输入0返回" << endl;
        cin >> n;
        if (!n)
            return;
        n--;
        if (n >= 0 && n < relist.size()) {

            for (int i = 0; i < booklist.size(); i++)
            {
                if (!strcmp(relist[n].book, booklist[i].name)) {
                    booklist[i].status = 0;
                    break;
                }

            }
            relist.erase(relist.begin() + n);

            cout << "删除成功" << endl;

            writerecord();

        }
        else {
            cout << "您输入的序号不在此列" << endl;
            whh();
        }


    }
    return;
}
void modifyrecord() {
    showrecord();
    cout << "输入对应序号修改此记录" << endl;
    int i;
    int flag = 0;
    cin >> i;
    i--;

    record a;

    while (flag <= 0) {
        flag = 0;

        cout << "请输入用户 ：";
        cin >> a.user;
        for (auto i : stlist)
            if (!strcmp(a.user, i.username)) {
                flag = 1;
                break;
            }
        if (flag == 0) {
            cout << "用户不存在 不能使用管理员账号" << endl;
            cout << "输入0返回继续";
            ;
            int l;
            cin >> l;
            if (!l)
                return;
            continue;
        }
        else {
            cout << "请输入图书 ：";

            cin >> a.book;
            for (auto i = booklist.begin(); i < booklist.end(); i++)
                if (!strcmp(a.book, (*i).name)) {
                    flag = 1;
                    if ((*i).status == 1)
                    {
                        cout << "图书已借出" << endl;
                        cout << "输入0返回继续";
                        ;
                        int l;
                        cin >> l;
                        if (!l)
                            return;
                        continue;
                        flag = -1;
                    }
                    (*i).status = 1;//借阅状态
                }
            if (flag == -1) {
                continue;
            }
            if (flag == 0) {
                cout << "图书不存在" << endl;

                cout << "输入0返回继续";
                ;
                int l;
                cin >> l;
                if (!l)
                    return;
                continue;
            }
            cout << "请输入借书时间 ：";
            cin >> a.time1;
            cout << "请输入还书时间 ：";
            cin >> a.time2;
            for (int k = 0; k < booklist.size(); k++)
            {
                if (!strcmp(relist[i].book, booklist[k].name)) {
                    booklist[k].status = 0;
                    break;
                }

            }
            relist[i] = a;
            writerecord();
        }
    }
    return;

}
void modifybook() {
    showbook();
    cout << "输入对应序号修改此记录" << endl;
    int i;

    cin >> i;
    i--;
    record a;
    int flag = 0;
    while (flag == 0) {
        flag = 1;
        book a;
        cout << "\n请输入图书名 ：";
        cin >> a.name;
        for (auto i : booklist)
            if (!strcmp(a.name, i.name)) {
                flag = 0;
            }
        if (flag == 0) {
            cout << "添加失败，图书名已存在" << endl;
            whh();
            continue;
        }
        else {
            cout << "请输入ISBN ：";

            cin >> a.ibsn;
            for (auto i : booklist)
                if (!strcmp(a.ibsn, i.ibsn)) {
                    flag = 0;
                }
            if (flag == 0) {
                cout << "添加失败，IBSN号已存在" << endl;
                whh();
                continue;
            }
            cout << "请输入作者 ：";
            cin >> a.author;
            cout << "请输入出版社 ：";
            cin >> a.publish;
            cout << "请输入价格 ：";
            cin >> a.price;
            booklist[i] = a;
            writebook();
        }
    }
    return;
}
void findbook() {
    int select = -1;
    while (1) {
        int count = 0;

        char conCharArr[40];


        if (select == 0)
        {

            return;
        }
        if (select > -1 && select <= 4) {
            if (select == 1 || select == 2 || select == 3 || select == 4) {
                cout << "请输入筛选条件：";
                cin >> conCharArr;
            }
        }

        printf("\n%-5s%-15s%-18s%-14s%-15s%-12s\n\n", "序号", "图书名", "ISBN", "作者", "出版社", "价格");
        for (int i = 0; i < booklist.size(); i++)
            if (select == -1
                || select == 1 && strstr(booklist[i].name, conCharArr) //根据图书名,模糊查询

                || select == 2 && strstr(booklist[i].ibsn, conCharArr) //根据ISBN,模糊查询
                || select == 3 && strstr(booklist[i].author, conCharArr) //根据作者,模糊查询
                ) {


                printf("%-5d%-15s%-18s%-14s%-15s%-12lf \n\n", i + 1
                    , booklist[i].name

                    , booklist[i].ibsn
                    , booklist[i].author
                    , booklist[i].publish
                    , booklist[i].price
                );
                count++;
            }



            else booklist.erase(booklist.begin() + (i--));
        cout << "共" << count << "条结果\n";








        cout << "【筛选器：你可以在以上结果的基础上，进行以下条件筛选】\n";

        cout << "1：按 图书名 筛选\n";
        cout << "2：按 ISBN 筛选\n";
        cout << "3：按 作者 筛选\n";
        cout << "4：刷新\n";
        cout << "0：退出\n";
        cout << "请输入选择：";

        cin >> select;
        if (select == 4)
        {
            select = -1;
            booklist.clear();
            readbook();
            continue;
        }
    }
    readbook();
    return;
}
void findrecord() {
    int select = -1;
    while (1) {
        int count = 0;

        char conCharArr[40];


        if (select == 0)
        {

            return;
        }
        if (select > -1 && select <= 4) {
            if (select == 1 || select == 2 || select == 3 || select == 4) {
                cout << "请输入筛选条件：";
                cin >> conCharArr;
            }
        }

        printf("\n%-5s%-15s%-15s%-10s%\n\n", "序号", "用户", "图书", "借书时间", "还书时间");
        for (int i = 0; i < relist.size(); i++)
            if (select == -1
                || select == 1 && strstr(relist[i].user, conCharArr) //根据用户,模糊查询

                || select == 2 && strstr(relist[i].book, conCharArr) //根据图书,模糊查询

                ) {
                printf("%-5d%-15s%-15s%-10d% \n\n", i + 1
                    , relist[i].user
                    , relist[i].book
                    , relist[i].time1
                    , relist[i].time2

                );


                count++;
            }



            else relist.erase(relist.begin() + (i--));
        cout << "共" << count << "条结果\n";








        cout << "【筛选器：你可以在以上结果的基础上，进行以下条件筛选】\n";

        cout << "1：按 用户 筛选\n";
        cout << "2：按 图书 筛选\n";

        cout << "3：刷新\n";
        cout << "0：退出\n";
        cout << "请输入选择：";

        cin >> select;
        if (select == 3)
        {
            select = -1;
            relist.clear();
            readrecord();

        }
    }
    readrecord();
    return;
}


void sortbook() {
    while (1)
    {
        int select, i, j;
        int n = booklist.size();

        cout << "1：按 图书名 排序\n";
        cout << "2：按 ISBN 排序\n";
        cout << "3：按 作者 排序\n";
        cout << "4：按 出版社 排序\n";
        cout << "5：按 价格 排序\n";
        cout << "0：退出\n";
        cout << "请输入选择：";
        cin >> select;
        if (select == 0)
        {
            writebook();
            return;
        }

        for (i = 0; i < n - 1; i++)
        {


            for (j = i + 1; j < n; j++)
            {
                if (0
                    || select == 1 && strcmp(booklist[j].name, booklist[i].name) > 0

                    || select == 2 && strcmp(booklist[j].ibsn, booklist[i].ibsn) > 0
                    || select == 3 && strcmp(booklist[j].author, booklist[i].author) > 0
                    || select == 4 && strcmp(booklist[j].publish, booklist[i].publish) > 0
                    || select == 5 && booklist[j].price - booklist[i].price > 0
                    ) {

                }
                else  swap(booklist[i], booklist[j]);


            }

        }
        showbook();
    }
}

void sortrecord() {
    while (1)
    {
        int select, i, j;
        int n = relist.size();

        cout << "1：按 用户 排序\n";
        cout << "2：按 图书 排序\n";
        cout << "3：按 借书时间 排序\n";
        cout << "4：按 还书时间 排序\n";


        cout << "0：退出\n";
        cout << "请输入选择：";
        cin >> select;
        if (select == 0)
        {
            writerecord();
            return;
        }

        for (i = 0; i < n - 1; i++)
        {


            for (j = i + 1; j < n; j++)
            {
                if (0
                    || select == 1 && strcmp(relist[j].user, relist[i].user) > 0
                    || select == 2 && strcmp(relist[j].book, relist[i].book) > 0
                    || select == 3 && relist[j].time1 - relist[i].time1 > 0
                    || select == 4 && relist[j].time2 - relist[i].time2 > 0

                    ) {

                }
                else  swap(relist[i], relist[j]);


            }

        }
        showrecord();
    }
}
