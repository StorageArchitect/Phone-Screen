
typedef enum {false, true}bool;;
bool isSubString(char *str1, char *str2) {
  return strstr(str1,str2) == NULL ? false : true;
}

// the rotated string will be a substring of the concatenated original string
void isRotatedString(){
  char str1[]="waterbottle";
  char str2[]="erbottlewat";
  char str3[]="erbottlewt";
  char str[strlen(str1) + strlen(str2)];
  strcpy(str,str1);
  strcat(str,str1);
  bool value = isSubString(str,str2);
  printf("String %s is a rotation of %s ? %d\n",str2,str1,value);
  value = isSubString(str,str3);
  printf("String %s is a rotation of %s ? %d\n",str3,str1,value);
}

int main() {
  isRotatedString();
  return 0;
}