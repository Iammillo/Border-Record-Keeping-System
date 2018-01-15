#include "dataformat.h"
#include<cstdlib>
#include<cstring>



DataFormat::DataFormat(char *mes)
{
    int n=0,len,pos=0;
    len = strlen(mes);

    for(int i=0;i<len;i++)
    {
        if(mes[i]=='/')
        {
            i++;
            n++;
            pos =0;
        }
        switch(n)
        {
        case 0:
                name[pos++]=mes[i];
                name[pos]='\0';
            break;

        case 1:
            address[pos++]=mes[i];
            address[pos]='\0';
        break;

        case 2:
            father[pos++]=mes[i];
            father[pos]='\0';
        break;

        case 3:
            mother[pos++]=mes[i];
            mother[pos]='\0';
        break;

        case 4:
            nationality[pos++]=mes[i];
            nationality[pos]='\0';
        break;

        case 5:
            year[pos++]=mes[i];
            year[pos]='\0';
        break;

        case 6:
            month[pos++]=mes[i];
            month[pos]='\0';
        break;

        case 7:
            day[pos++]=mes[i];
            day[pos]='\0';
        break;

        case 8:
            passport[pos++]=mes[i];
            passport[pos]='\0';
        break;

        case 9:
            type = mes[i];
            break;

        case 10:
            gender=mes[i];
            break;

        }
    }


}

bool DataFormat::validitychar(char *str)
{
    int len = strlen(str);
    bool result = true;
    if(len ==0)
    {
        result = false;
        return result;
    }
    for(int i =0;i<len;i++)
    {
        if(!((str[i]>64&&str[i]<91)||(str[i]>96&&str[i]<123)||str[i]==32))
        {
            result = false;
            break;
        }

    }
    return result;

}




bool DataFormat::validityint(char *str)
{
    int len = strlen(str);
    bool result = true;
    if(len ==0)
    {
        result = false;
        return result;
    }
    for(int i =0;i<len;i++)
    {
        if(!(str[i]>47&&str[i]<58))
        {
                result = false;
                break;
        }

    }
    return result;

}





 bool DataFormat::check_validity(char *error)
        {


                if(!validitychar(name))
        {
                strcpy(error,"Error in name");
                return false;
            }
                if(strlen(address)==0)
                {
                    strcpy(error,"Error in Address");
                    return false;
                }

                if(!validitychar(mother))
        {
                strcpy(error,"Error in Mother's name");
                return false;
    }
                if(!validitychar(father))
        {
                strcpy(error,"Error in Father's name");
                return false;
    }

                if(!validitychar(nationality))
        {
                strcpy(error,"Error in Nationality.");
                return false;
    }
                if(!(validityint(year)&&validityint(day)&&validityint(month)))
        {
                strcpy(error,"Error in date of birth.");
                return false;
    }

                if(!(check_year(atoi(year),atoi(month),atoi(day))))
                        {
                    strcpy(error,"Invalid date. No such date exist.");
                    return false;

                         }

                if(!(validityint(passport)))
        {
                strcpy(error,"Error in passport number.");
                return false;
    }
                else
                {
                    strcpy(error,"Everything valid!!!");
                    return true;
                }

    }




bool DataFormat::check_year(int x, int y, int z)
        {
                   if(x<1||y<1||y>12||z<1||z>31)
                    {
                         return false;
                    }
                   else
                        {
                            if(leap(x))
                                {
                                    if(y==2 && z>29)
                                    return false;

                                 }

                                else
                                    {

                                switch(y)
                                       {
                                                    case 2:
                                                            if(z>28)return false;break;
                                                    case 4:
                                                    case 6:
                                                    case 9:
                                                    case 11:if(z>30){return false;break;}

                                                    default:return true;
                                         }
                            }

                            }
return true;
    }



bool DataFormat::leap(int x)
        {
                   if(x%4!=0)
        {
                   return false;

    }
                   else
        {
                   if(x%100!=0)
                   return true;
                   else
                   if(x%400==0)
                   return true;
                   else
                   return false;

    }

}

void DataFormat::changetostring(char *message)
{
    strcpy(message,name);
    strcat(message,"/");
    strcat(message,address);
    strcat(message,"/");
    strcat(message,father);
    strcat(message,"/");
    strcat(message,mother);
    strcat(message,"/");
    strcat(message,nationality);
    strcat(message,"/");
    strcat(message,year);
    strcat(message,"/");
    strcat(message,month);
    strcat(message,"/");
    strcat(message,day);
    strcat(message,"/");
    strcat(message,passport);
    strcat(message,"/");
    int len=strlen(message);
    message[len]= type;
    message[len+1]='/';
    message[len+2] = gender;
    message[len+3] = '\0';


}

