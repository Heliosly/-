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
    char numb[8]; //����֤��
    char gender[6] ;
    int age;
};
struct admin {
    char username[15];
    char password[15];
};
struct book {
    char name[15]; 
     
    char ibsn[18]; 
    char author[14]; // ����
    char publish[15]; // ������
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
void whh() { cout << "\n���뻻�з�����" << endl;   getchar(); while (   char cc = getchar()) { if (cc == '\n') break; };}
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
    while(!islogin)
    {
        cout << "*---------------------------------------------*\n*------------1����½\n*------------2��ע��\n*---------------------------------------------*\n������ѡ��";
        int a = 0;
        cin >> a;
        if (a == 1) {
            Login();
        }
        else if (a == 2) {
            Register();
        }
    }
    while(1)
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
    while (fscanf(fp, "%s%s", a.username,a.password)!=EOF) {
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
    while (fscanf(fp, "%s%s%s%s%s%d", a.username, a.password,a.name,a.gender,&a.numb ,& a.age) != EOF) {
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
    while (fscanf(fp, "%s%s%s%s%lf%d", a.name,  a.ibsn, a.author, a.publish, &a.price,&a.status) != EOF) {
        booklist.push_back(a);
    }
    fclose(fp);
}
void writebook() {
    FILE* fp = fopen("Book.txt", "w+");
    for (auto i : booklist) {
        fprintf(fp, "%s %s %s %s %lf %d\n", i.name,  i.ibsn, i.author, i.publish, i.price,i.status);

    }
    fclose(fp);
}
void writest() {
    FILE* fp = fopen("St.txt", "w+");

for (auto i : stlist) {
        fprintf(fp, "%s %s %s %s %s %d\n", i.username, i.password,i.name,i.gender, i.numb,i.age);

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
        cout << "�������˺ţ�";
        cin >> username;
        cout << "���������룺";
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

        if(!islogin) {
            cout << "��¼ʧ��"<<endl;
            cout << "���� 0 ����" << endl;
            cout << "���� 1 ����" << endl;
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
    while (flag==0) {
        flag = 1;
        cout << "*---------------------------------------------*\n*------------0:���� \n";
        cout << "*------------1:ע�����Ա \n";
        cout << "*------------2:ע���û� \n";
        cout << "*---------------------------------------------*\n������ѡ��";
        int slect = 0;
        cin >> slect;

        if (slect == 1) {
            admin a;
            cout << "�������˺ţ�";
            cin >> a.username;
          
            for (auto i : adminlist) {
                if (!strcmp(a.username,i.username))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "ע��ʧ��,�û����ظ�" << endl;
                continue;
            }
            cout << "���������룺";
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
            cout << "�������˺ţ�";
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
                cout << "ע��ʧ��,�û����ظ�" << endl;
                continue;
            }
            cout << "���������룺";
            cin >> a.password;
            cout << "���������� ��";

            cin >> a.name;
            cout << "�������Ա� ��";

            cin >> a.gender;
            cout << "���������� ��";

            cin >> a.age;
            cout << "���������֤�� ��";
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
	
    	cout << "*------------------���˵�---------------------*\n";
	cout << "*-------------1 :����û�\n";
	cout << "*-------------2 :ɾ���û�\n";
	cout << "*-------------3 :�޸��û�\n";
	cout << "*-------------4 :�����û�\n";
	cout << "*-------------5 :�����û�\n";
	cout << "*-------------6 :���ͼ��\n";
	cout << "*-------------7 :ɾ��ͼ��\n";
	cout << "*-------------8 :�޸�ͼ��\n";
	cout << "*-------------9 :����ͼ��\n";
	cout << "*-------------10 :����ͼ��\n";
	cout << "*-------------11 :��ӽ��ļ�¼\n";
	cout << "*-------------12 :ɾ�����ļ�¼\n";
	cout << "*-------------13 :�޸Ľ��ļ�¼\n";
	cout << "*-------------14 :���ҽ��ļ�¼\n";
	cout << "*-------------15 :������ļ�¼\n";
	cout << "*-------------0:�˳�\n";
	cout << "*------------(-1):�ǳ�\n";
	cout << "*------------(-2):�ҵ�\n";
	cout << "*---------------------------------------------*\n";
	cout << "������ѡ��";
}
void stmenu() {
	
	cout << "*------------------���˵�---------------------*\n";
	cout << "*-------------1 :����ͼ��\n";
	cout << "*-------------2 :����ͼ��\n";
	cout << "*-------------3 :��ӽ��ļ�¼\n";
	cout << "*-------------4 :�޸Ľ��ļ�¼\n";
	cout << "*-------------5 :���ҽ��ļ�¼\n";
	cout << "*-------------6 :������ļ�¼\n";
	cout << "*-------------0:�˳�\n";
	cout << "*------------(-1):�ǳ�\n";
	cout << "*------------(-2):�ҵ�\n";
	cout << "*---------------------------------------------*\n";
	cout << "������ѡ��";
}
void adduser() {
    bool flag = 0;
    while (flag == 0) {
        flag = 1;
        cout << "*---------------------------------------------*\n*------------0:���� \n";
        cout << "*------------1:��ӹ���Ա \n";
        cout << "*------------2:����û� \n";
        cout << "*---------------------------------------------*\n������ѡ��";
        int slect = 0;
        cin >> slect;

        if (slect == 1) {
            admin a;
            cout << "�������˺ţ�";
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
                cout << "���ʧ��,�û����ظ�" << endl;
                continue;
            }
            cout << "���������룺";
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
            cout << "�������˺ţ�";
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
                cout << "���ʧ��,�û����ظ�" << endl;
                continue;
            }
            cout << "���������룺";
            cin >> a.password;
            cout << "���������� ��";

            cin >> a.name;
            cout << "�������Ա� ��";

            cin >> a.gender;
            cout << "���������� ��";

            cin >> a.age;
            cout << "���������֤�� ��";
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
    int count=0;
    printf("\n%-5s%-15s%-15s%-15s%-8s%-10s%-18s\n\n", "���", "�û���", "����", "����", "�Ա�", "����", "��ַ", "����֤��");
    for (int i = 0; i < adminlist.size();i++)
    {
        printf("%-5d%-15s%-15s%-15s%-8s%-10s%-18s \n\n", i + 1, adminlist[i].username, adminlist[i].password, "����Ա"
            , "��"
            , "��"
            , "��"
        );
        count++;
    }
    for (int i = 0; i < stlist.size(); i++)
    {
        printf("%-5d%-15s%-15s%-15s%-8s%-10d%-18s \n\n", i + 1+adminlist.size(), stlist[i].username, stlist[i].password, stlist[i].name
            , stlist[i].gender
            , stlist[i].age
            , stlist[i].numb
        );
        count++;
    }
    cout << "      ��" << count << "�����\n";
   
    return;

}
void showst() {
    int count = 0;
    printf("\n%-5s%-15s%-15s%-15s%-8s%-10s%-18s\n\n", "���", "�û���", "����", "����", "�Ա�", "����", "��ַ", "����֤��");

    for (int i = 0; i < stlist.size(); i++)
    {
        printf("%-5d%-15s%-15s%-15s%-8s%-10d%-18s \n\n", i + 1, stlist[i].username, stlist[i].password, stlist[i].name
            , stlist[i].gender
            , stlist[i].age
            , stlist[i].numb
        );
        count++;
    }
    cout << "      ��" << count << "�����\n";
    return;
}
void deleteuser() {
    while(1)
    {
        showuser();
        int n;

        cout << "�������,ɾ������ɾ�����˺Ż�������0����" << endl;
        cin >> n;
        if (!n)
            return ;
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
            cout << "ɾ���ɹ�" << endl;
            writeadmin();
            writest();
        }
        else {
            cout << "���������Ų��ڴ���" << endl;
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
        if (select > -1&&select<=4) {
            if (select == 1 || select == 2 || select == 3 || select == 4) {
                cout << "������ɸѡ������";
                cin >> conCharArr;
            }
        }
        if(select==5) 
        {
            select = -1;
            stlist.clear();
            readst();
        }
        printf("\n%-5s%-15s%-15s%-15s%-8s%-10s%-18s\n\n", "���", "�û���", "����", "����", "�Ա�", "����", "��ַ", "����֤��");
        for (int i = 0; i < stlist.size(); i++)
            if (select == -1
                || select == 1 && strstr(stlist[i].username, conCharArr) //�����û���,ģ����ѯ
                || select == 2 && strstr(stlist[i].name, conCharArr) //��������,ģ����ѯ
                || select == 3 && strstr(stlist[i].gender, conCharArr) //�����Ա�,ģ����ѯ
                || select == 4 && strstr(stlist[i].numb, conCharArr) //���ݽ���֤��,ģ����ѯ
                ) {

                printf("%-5d%-15s%-15s%-15s%-8s%-10d%-18s \n\n", (++count), stlist[i].username, stlist[i].password, stlist[i].name
                    , stlist[i].gender
                    , stlist[i].age
                    , stlist[i].numb);


            }
            else stlist.erase(stlist.begin() + (i--));
            
       
       
        cout << "      ��" << count << "�����\n";
       



        cout << "��ɸѡ��������������Ͻ���Ļ����ϣ�������������ɸѡ��\n";
        cout << "0���˳�\n";
        cout << "1���� �û��� ɸѡ\n";
        cout << "2���� ���� ɸѡ\n";
        cout << "3���� �Ա� ɸѡ\n";
        cout << "4���� ����֤�� ɸѡ\n";
        cout << "5��ˢ��\n";
        cout << "������ѡ��";

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
        
        cout << "1���� �û��� ����\n";
        cout << "2���� ���� ����\n";
        cout << "3���� ���� ����\n";
        cout << "4���� �Ա� ����\n";
        cout << "5���� ���� ����\n";
        cout << "6���� ����֤�� ����\n";
        cout << "0���˳�\n";
        cout << "������ѡ��";
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
        printf("\n%-5s%-15s%-15s%-15s%-8s%-10s%-18s\n\n", "���", "�û���", "����", "����", "�Ա�", "����", "��ַ", "����֤��");

        for (int i = 0; i < stlist.size(); i++)
        {
            printf("%-5d%-15s%-15s%-15s%-8s%-10d%-18s \n\n", i + 1, stlist[i].username, stlist[i].password, stlist[i].name
                , stlist[i].gender
                , stlist[i].age
                , stlist[i].numb
            );
            count++;
        }
        cout << "      ��" << count << "�����\n";
    }
}
void modifyuser() {
    showst();
    cout << "�����Ӧ����޸Ĵ��û�" << endl;
    int i;
    int flag = 1;
    cin >> i;
    i--;
    char a[15];
    cout << "�������û��� ��";
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
        cout << "���������� ��";
        cin >> stlist[i].password;
        cout << "���������� ��";
        cin >> stlist[i].name;


        cout << "�������Ա� ��";
        cin >> stlist[i].gender;
        cout << "���������� ��";
        cin >> stlist[i].age;

        cout << "���������֤�� ��";
        cin >> stlist[i].numb;
        writest();
        cout << "                       �޸ĳɹ�"<<endl;
    }
    else cout << "         �޸�ʧ�ܣ��û����ظ� " << endl;
    whh();
    return ;
}
void addbook() {
   
   
        bool flag = 0;
        while (flag == 0) {
            flag = 1;
            book a;
            cout << "\n������ͼ���� ��";
            cin >> a.name;
            for(auto i:booklist)
            if (!strcmp(a.name, i.name)) {
                flag = 0;
            }
            if (flag == 0) {
                cout << "���ʧ�ܣ�ͼ�����Ѵ���" << endl;
                whh();
                continue;
            }
            else {
                cout << "������ISBN ��";
               
                cin >> a.ibsn;
                for (auto i : booklist)
                    if (!strcmp(a.ibsn, i.ibsn)) {
                        flag = 0;
                    }
                if (flag == 0) {
                    cout << "���ʧ�ܣ�IBSN���Ѵ���" << endl;
                    whh();
                    continue;
                }
                		cout << "���������� ��";
                        cin >> a.author;
                		cout << "����������� ��";
                        cin >> a.publish;
                		cout << "������۸� ��";
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
        cout << "�������û� ��";
        cin >> a.user;
        for (auto i : stlist)
            if (!strcmp(a.user, i.username)) {
                flag = 1;
                break;
            }
        if (flag == 0) {
            cout << "�û������ڲ��Ҳ���ʹ�ù���Ա�˺�" << endl;
            cout << "����0���ؼ���";
                ;
            int l;
            cin >> l;
            if (!l)
                return;
           
            continue;
        }
        else {
            cout << "������ͼ�� ��";
            flag = 0;
            cin >> a.book;
            if(!booklist.empty())
            for (auto i=booklist.begin();i<booklist.end();i++)
                if (!strcmp(a.book, (*i).name)) {
                    flag = 1;
                    if ((*i).status == 1)
                    {
                        cout << "ͼ���ѽ��" << endl;
                        cout << "����0���ؼ���";
                            ;
                        int l;
                        cin >> l;
                        if (!l)
                            return;
                        flag = -1;
                    }
                    (*i).status = 1;//����״̬
                }
            if (flag == -1) {
                continue;
            }
            if (flag == 0) {
                cout << "ͼ�鲻����" << endl;
                cout << "����0���ؼ���";
                    ;
                int l;
                cin >> l;
                if (!l)
                    return;
                continue;
            }
            		cout << "���������ʱ�� ��";
                    cin >> a.time1;
  		cout << "�����뻹��ʱ�� ��";
        cin >> a.time2;
        relist.push_back(a);
            writerecord();
        }
    }
    return;

}
void showbook() {
    printf("\n%-5s%-15s%-18s%-14s%-15s%-12s\n\n", "���", "ͼ����", "ISBN", "����", "������", "�۸�");
    		
    			int count = 0, i;
    			double priceSum = 0;
    			for (i = 0; i < booklist.size(); i++)
    			{
   
    					printf("%-5d%-15s%-18s%-14s%-15s%-12lf \n\n", i+1
    						, booklist[i].name
    						
    						, booklist[i].ibsn
    						, booklist[i].author
    						, booklist[i].publish
    						, booklist[i].price
    					);
    count++;
}
cout << "��" << count << "�����\n";
}
void showrecord() {
    		printf("\n%-5s%-15s%-15s%-10s%\n\n", "���", "�û�", "ͼ��", "����ʱ��", "����ʱ��");
		
			int count = 0, i;
		for(int i=0;i<relist.size();i++)
        {
            printf("%-5d%-15s%-15s%-10d% \n\n", i + 1
                , relist[i].user
                , relist[i].book
                , relist[i].time1
                , relist[i].time2

            );
            count++;
        }
        cout << "��" << count << "�����\n";
					
}
void deletebook() {
    while (1)
    {
        showbook();
        int n;

        cout << "�������,ɾ������ɾ�����鼮��������0����" << endl;
        cin >> n;
        if (!n)
            return;
        n--;
        if (n >= 0 && n < booklist.size()) {
            
                booklist.erase(booklist.begin() + n);
           
            cout << "ɾ���ɹ�" << endl;
            writebook();
           
        }
        else {
            cout << "���������Ų��ڴ���" << endl;
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

        cout << "�������,ɾ������ɾ���ļ�¼��������0����" << endl;
        cin >> n;
        if (!n)
            return;
        n--;
        if (n >= 0 && n < relist.size()) {
            
            for (int i = 0; i < booklist.size(); i++) 
            {
                if (!strcmp(relist[n].book, booklist[i].name)) {
                    booklist[i].status=0;
                    break;
                }
                
            }
            relist.erase(relist.begin() + n);

            cout << "ɾ���ɹ�" << endl;

            writerecord();
           
        }
        else {
            cout << "���������Ų��ڴ���" << endl;
            whh();
        }


    }
    return;
}
void modifyrecord() {
    showrecord();
    cout << "�����Ӧ����޸Ĵ˼�¼" << endl;
    int i;
    int flag = 0;
    cin >> i;
    i--;
    
    record a;
    
    while (flag <= 0 ) {
        flag = 0;
       
        cout << "�������û� ��";
        cin >> a.user;
        for (auto i : stlist)
            if (!strcmp(a.user, i.username)) {
                flag = 1;
                break;
            }
        if (flag == 0) {
            cout << "�û������� ����ʹ�ù���Ա�˺�" << endl;
            cout << "����0���ؼ���";
                ;
            int l;
            cin >> l;
            if (!l)
                return;
            continue;
        }
        else {
            cout << "������ͼ�� ��";

            cin >> a.book;
            for (auto i = booklist.begin(); i < booklist.end(); i++)
                if (!strcmp(a.book, (*i).name)) {
                    flag = 1;
                    if ((*i).status == 1)
                    {
                        cout << "ͼ���ѽ��" << endl;
                        cout << "����0���ؼ���";
                            ;
                        int l;
                        cin >> l;
                        if (!l)
                            return;
                        continue;
                        flag = -1;
                    }
                    (*i).status = 1;//����״̬
                }
            if (flag == -1) {
                continue;
            }
            if (flag == 0) {
                cout << "ͼ�鲻����" << endl;
                
                cout << "����0���ؼ���";
                    ;
                int l;
                cin >> l;
                if (!l)
                    return;
                continue;
            }
            cout << "���������ʱ�� ��";
            cin >> a.time1;
            cout << "�����뻹��ʱ�� ��";
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
    cout << "�����Ӧ����޸Ĵ˼�¼" << endl;
    int i;
 
    cin >> i;
    i--;
    record a;
    int flag = 0;
    while (flag == 0) {
        flag = 1;
        book a;
        cout << "\n������ͼ���� ��";
        cin >> a.name;
        for (auto i : booklist)
            if (!strcmp(a.name, i.name)) {
                flag = 0;
            }
        if (flag == 0) {
            cout << "���ʧ�ܣ�ͼ�����Ѵ���" << endl;
            whh();
            continue;
        }
        else {
            cout << "������ISBN ��";

            cin >> a.ibsn;
            for (auto i : booklist)
                if (!strcmp(a.ibsn, i.ibsn)) {
                    flag = 0;
                }
            if (flag == 0) {
                cout << "���ʧ�ܣ�IBSN���Ѵ���" << endl;
                whh();
                continue;
            }
            cout << "���������� ��";
            cin >> a.author;
            cout << "����������� ��";
            cin >> a.publish;
            cout << "������۸� ��";
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
                cout << "������ɸѡ������";
                cin >> conCharArr;
            }
        }
       
        printf("\n%-5s%-15s%-18s%-14s%-15s%-12s\n\n", "���", "ͼ����", "ISBN", "����", "������", "�۸�");
        for (int i = 0; i < booklist.size(); i++)
            if (select == -1
                					|| select == 1 && strstr(booklist[i].name, conCharArr) //����ͼ����,ģ����ѯ
                					
                					|| select == 2 && strstr(booklist[i].ibsn, conCharArr) //����ISBN,ģ����ѯ
                					|| select == 3 && strstr(booklist[i].author, conCharArr) //��������,ģ����ѯ
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
        cout << "��" << count << "�����\n";


       





        cout << "��ɸѡ��������������Ͻ���Ļ����ϣ�������������ɸѡ��\n";
        
        cout << "1���� ͼ���� ɸѡ\n";
        cout << "2���� ISBN ɸѡ\n";
        cout << "3���� ���� ɸѡ\n";
        cout << "4��ˢ��\n";
        cout << "0���˳�\n";
        cout << "������ѡ��";

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
                cout << "������ɸѡ������";
                cin >> conCharArr;
            }
        }
       
        printf("\n%-5s%-15s%-15s%-10s%\n\n", "���", "�û�", "ͼ��", "����ʱ��", "����ʱ��");
        for (int i = 0; i < relist.size(); i++)
            if (select == -1
                || select == 1 && strstr(relist[i].user, conCharArr) //�����û�,ģ����ѯ

                || select == 2 && strstr(relist[i].book, conCharArr) //����ͼ��,ģ����ѯ
                
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
        cout << "��" << count << "�����\n";








        cout << "��ɸѡ��������������Ͻ���Ļ����ϣ�������������ɸѡ��\n";

        cout << "1���� �û� ɸѡ\n";
        cout << "2���� ͼ�� ɸѡ\n";
        
        cout << "3��ˢ��\n";
        cout << "0���˳�\n";
        cout << "������ѡ��";

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

    cout << "1���� ͼ���� ����\n";
	cout << "2���� ISBN ����\n";
	cout << "3���� ���� ����\n";
	cout << "4���� ������ ����\n";
	cout << "5���� �۸� ����\n";
        cout << "0���˳�\n";
        cout << "������ѡ��";
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

        	cout << "1���� �û� ����\n";
 	cout << "2���� ͼ�� ����\n";
 	cout << "3���� ����ʱ�� ����\n";
 	cout << "4���� ����ʱ�� ����\n";
   	

        cout << "0���˳�\n";
        cout << "������ѡ��";
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