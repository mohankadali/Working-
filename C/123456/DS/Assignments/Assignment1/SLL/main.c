#include"header.h"

struct node{
    int data;
    struct node *link;
}*head;

int main ()                                             //program starts from here.....    
{
    int option, data, pos, num;

    char ch;
  
    while(1) {
        printf("To insert press    ->1\nTo delete press    ->2\nTo print press     ->3\nTo exit press      ->4\n");
        fgets((char*)&option,3,stdin);         
        option = atoi((char*)&option);  
        switch(option){   
            case 1:
                do
                {   
                    printf("enter the question number for insertion (1 to 9)\n");
                    fgets((char*)&option,3,stdin); 
                    option = atoi((char*)&option);  
                    switch(option){
                        case 1:
                            printf("enter data\n");
                            fgets((char*)&data, sizeof (int), stdin);
                            data=atoi((char*)&data);
                            add_frnt (data);
                            break;
                        case 2:
                            printf("enter data\n");
                            fgets((char*)&data, 3, stdin);
                            data=atoi((char*)&data);
                            add_end (data);
                            break;
                        case 3:
                            printf("enter data and position\n");
                            fgets((char*)&data, 3, stdin);
                            data=atoi((char*)&data);
                            fgets((char*)&pos, 3, stdin);
                            pos=atoi((char*)&pos);
                            add_pos (data, pos);
                            break;
                        case 4:
                            printf("enter data and position\n");
                            fgets((char*)&data, 3, stdin);
                            data=atoi((char*)&data);
                            fgets((char*)&pos, 3, stdin);
                            pos=atoi((char*)&pos);
                            add_before (data, pos);
                            break;
                        case 5:
                            printf("enter data and positon\n");
                            fgets((char*)&data, 3, stdin);
                            data=atoi((char*)&data);
                            fgets((char*)&pos, 3, stdin);
                            pos=atoi((char*)&pos);
                            add_after (data, pos);
                            break;
                        case 6:
                            printf("enter data and num\n");
                            fgets((char*)&data, 3, stdin);
                            data=atoi((char*)&data);
                            fgets((char*)&num, 3, stdin);
                            num=atoi((char*)&num);
                            add_before_num (data, num);
                            break;
                        case 7:
                            printf("enter data and num\n");
                            fgets((char*)&data, 3, stdin);
                            data=atoi((char*)&data);
                            fgets((char*)&num, 3, stdin);
                            num=atoi((char*)&num);
                            add_after_num (data, num);
                            break;
                        case 8:
                            printf("enter data\n");
                            fgets((char*)&data, 3, stdin);
                            data=atoi((char*)&data);
                            add_mid (data);
                            break;
                        case 9:
                            printf("enter data\n");
                            fgets((char*)&data, 3, stdin);
                            data=atoi((char*)&data);
                            add_pen (data);
                            break;

                        default: printf("invalid\n"); 			

                    }

                    printf("enter the y if u want to insert more....\n");
                    fgets(&ch,10,stdin);

                }while(ch=='y');
                break;
            case 2:   
                do
                {   
                    printf("enter the question number for deletion (1 to 9)\n");
                    fgets((char*)&option,3,stdin);      
                    option = atoi((char*)&option);  
                    switch(option){
                        case 1:
                            del_frnt();
                            break;
                        case 2:
                            del_end();
                            break;
                        case 3:
                            printf("enter pos to delete\n");
                            fgets((char*)&pos, 3, stdin);
                            pos=atoi((char*)&pos);
                            del_pos(pos);
                            break;
                        case 4:
                            printf("enter pos to delete before pos\n");
                            fgets((char*)&pos, 3, stdin);
                            pos=atoi((char*)&pos);
                            del_before(pos);
                            break;
                        case 5:
                            printf("enter pos to delete afeter pos\n");
                            fgets((char*)&pos, 3, stdin);
                            pos=atoi((char*)&pos);
                            del_after(pos);
                            break;
                        case 6:
                            printf("enter num to delete befire num\n");
                            fgets((char*)&num, 3, stdin);
                            num=atoi((char*)&num);
                            del_before_num (num);
                            break;
                        case 7:
                            printf("enter num to delete after num\n");
                            fgets((char*)&num, 3, stdin);
                            num=atoi((char*)&num);
                            del_after_num (num);
                            break;
                        case 8:
                            del_mid();
                            break;
                        case 9:
                            del_pen();
                            break;
                        default:  

                            printf("enter the y if u want to delete more.....\n");
                            fgets(&ch,10,stdin);
                            break;
                    }
                }while(ch=='y');
                break;
            case 3:print();
                   break;
            case 4:exit(0);
            default:printf("invalid entry\n");
                    break;
        }
    }
}
