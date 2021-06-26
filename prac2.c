/*#include <stdio.h>
int main() {
    double n1, n2, n3;
    printf("Enter three different numbers: ");
    scanf("%lf %lf %lf", &n1, &n2, &n3);

    // if n1 is greater than both n2 and n3, n1 is the largest
    if (n1 >= n2 && n1 >= n3)
        printf("%.2f is the largest number.", n1);

    // if n2 is greater than both n1 and n3, n2 is the largest
    if (n2 >= n1 && n2 >= n3)
        printf("%.2f is the largest number.", n2);

    // if n3 is greater than both n1 and n2, n3 is the largest
    if (n3 >= n1 && n3 >= n2)
        printf("%.2f is the largest number.", n3);

    return 0;
}*/
/*#include <stdio.h>
int main()
{
  char city[40];
  printf("Enter your favorite city: ");
  //gets(city);
  // Note: for safety, use
   fgets(city,40,stdin);

  puts(city);

  return 0;
}*/ 
/*#include <stdio.h>
int main()
{
  char info[ ] = "Snoqualmie WA 13190";
  char city[50];
  char state[50];
  int population;
  sscanf(info, "%s %s %d", city, state, &population);
  printf("%d people live in %s, %s.", population, city, state);

  return 0;
} */
/*#include <stdio.h>
#include <string.h>

int main()
{
    char s1[ ] = "The grey fox";
    char s2[ ] = "jumped.";
    
    strcat(s1, s2);
    printf("%s\n", s1);
    printf("Length of s1 is %d\n", strlen(s1));
    strcpy(s1, s2);
    printf("s1 is now %s \n", s1);

    return 0;
} */

/*#include <stdio.h>
int main()
{
    char input[10 ];
    int num;
    
    
    printf("Enter a number: ");
    gets(input);
    num = atoi(input);
      
    printf("You entered %d", num);

    return 0;
}*/

/*#include <stdio.h>

int main()
{
  char *trip[5] = {
      "suitcase",
      "passport",
      "ticket"
  };

  printf("Please bring the following:\n");
  for (int i = 0; i < 3; i++) {
    printf("%s\n", trip[i]);
  }  

  return 0;
} */

/*#include <stdio.h>

struct student {
    int age;
    int grade;
    char name[40];
};

int main() {
    // declare two variables 
    struct student s1;
    struct student s2;
    
    s1.age = 19;
    s1.grade = 9;
    sprintf(s1.name, "John Bighimer");
    
    s2.age = 22;
    s2.grade = 10;
    sprintf(s2.name, "Batman Jokerson");
    // do not work s2.name[] = "Pushkar wani";
    
    printf("Student: %s, %d\n", s1.name, s1.age);
    printf("Student: %s, %d\n", s2.name, s2.age);
    
    return 0;
}*/

/*#include <stdio.h>

struct student {
    int age;
    int grade;
    char name[40];
};

int main() {
    // declare two variables 
    struct student s1 = {19, 9, "John Birghimer"};
    struct student s2 = {22, 10, "Batman Jokerson"};
    
    printf("Student: %s, %d\n", s1.name, s1.age);
    printf("Student: %s, %d\n", s2.name, s2.age);
    
    return 0;
}*/

/*#include <stdio.h>
#include <string.h>

struct course {
  int id;
  char title[40];
  float hours; 
};

int main() {
  struct course cs1 = {341279, "Intro to C++", 12.5};
  struct course cs2;

  // initialize cs2 
  cs2.id = 341281;
  strcpy(cs2.title, "Advanced C++");
  cs2.hours = 14.25;
   
   //display course info 
  printf("%d\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours);
  printf("%d\t%s\t%4.2f\n", cs2.id, cs2.title, cs2.hours);
  
  return 0;
}*/

/*#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char title[40];
    float hours; 
} course;

int main() {
    course cs1;
    course cs2;

    cs1.id = 123456;
    strcpy(cs1.title, "JavaScript Basics");
    cs1.hours = 12.30;

    // initialize cs2 
    cs2.id = 341281;
    strcpy(cs2.title, "Advanced C++");
    cs2.hours = 14.25;
       
    // display course info 
    printf("%d\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours);
    printf("%d\t%s\t%4.2f\n", cs2.id, cs2.title, cs2.hours);
  
    return 0;
}*/

// structures inside structures.......................................................................

/*#include <stdio.h>

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  float radius;
  point center;
} circle; 

int main() {
    point p;
    p.x = 3;
    p.y = 4;
    
    circle c;
    c.radius = 3.14;
    c.center = p;
    
    printf("Circle radius is %.2f, center is at (%d, %d)", c.radius, c.center.x, c.center.y);
  
    return 0;
}*/

//nested curly braces for struct inside struct...............................................

/*#include <stdio.h>

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  float radius;
  point center;
} circle; 

int main() {
    circle c = {4.5, {1, 3}};
    printf("%3.1f %d,%d", c.radius, c.center.x, c.center.y);
    // 4.5  1,3 
  
    return 0;
}*/

// Pointers to structures.................................................(this pointer ->).......................

/*#include <stdio.h>
#include <string.h>

// Student Structure Definition
struct student{
    char name[50];
    int number;
    int age;
};

// Struct pointer as a function parameter
void showStudentData(struct student *st) {
    printf("\nStudent:\n");
    printf("Name: %s\n", st->name); // *(st.name)...... st.name = &st1.name[look main() function].....,*(&st1.name)==st1.name
    printf("Number: %d\n", st->number);
    printf("Age: %d\n", st->age);
}

int main() {
    // New Student Record Creation
    struct student st1;
    struct student st2;
    
    // Filling Student 1 Details
    strcpy(st1.name, "Krishna");
    st1.number = 5;
    st1.age = 21;
    
    // Filling Student 2 Details
    strcpy(st2.name, "Max");
    st2.number = 9;
    st2.age = 15;
    
    // Displaying Student 1 Details
    showStudentData(&st1);
    
    // Displaying Student 2 Details
    showStudentData(&st2);
    
    return 0;
}*/

//Structures as function parameters...........................................................
/*#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char title[40];
    float hours; 
} course;

void update_course(course *class);
void display_course(course class);

int main() {
    course cs2;
    update_course(&cs2);
    display_course(cs2);
    return 0;
}

void update_course(course *class) {
    strcpy(class->title, "C++ Fundamentals");
    class->id = 111;
    class->hours = 12.30;
}

void display_course(course class) {
    printf("%d\t%s\t%3.2f\n", class.id, class.title, class.hours);
} */

//Array of structures

/*#include <stdio.h>
typedef struct {
  int h;
  int w;
  int l;
} box;
int main() {
  box boxes[3] = {{2, 6, 8}, {4, 6, 6}, {2, 6, 9}};
  int k, volume;
  
  for (k = 0; k < 3; k++) {
    volume = boxes[k].h*boxes[k].w*boxes[k].l;
    printf("box %d volume %d\n", k, volume);
  }
  return 0;
}*/

//Union..................................................................................

// The last assignment will have the correct values, rest values gets deleted automatically.
//The last assignment overrides previous assignments, which is why str stores a value and accessing int_num and fl_num is meaningless. 

/*#include <stdio.h>
#include  <string.h>

union val {
  int int_num;
  float fl_num;
  char str[20]; 
};
int main() {  
  union val test;

  test.int_num = 123;
  test.fl_num = 98.76;
  strcpy(test.str, "hello");
  test.fl_num = 98.76;

  printf("%d\n", test.int_num);
  printf("%f\n", test.fl_num);
  printf("%s\n", test.str);
  printf("%f\n", test.fl_num);
  return 0;
}*/

// Structures and unions....................................................................................

/*#include <stdio.h>
#include <string.h>

typedef struct {
  char make[20];
  int model_year;
  int id_type; 
  union {
    int id_num;
    char VIN[20]; 
  } id;
} vehicle;

int main() {  
  vehicle car1;
  strcpy(car1.make, "Ford");
  car1.model_year = 2017;
  car1.id_type = 10;
  car1.id.id_num = 123098;
  strcpy(car1.id.VIN,"what is VIN");
  
  printf("Make: %s\n", car1.make);
  printf("Model Year: %d\n", car1.model_year);
  if (car1.id_type == 0)
    printf("ID: %d\n", car1.id.id_num);
  else
    printf("ID: %s\n", car1.id.VIN);

  return 0;
}*/

// Union to pointers........................................................................................

/*#include <stdio.h>
#include <string.h>

union val {
  int int_num;
  float fl_num;
  char str[20]; 
};

int main() {  
  union val info;
  union val *ptr = NULL;
  ptr = &info;
  ptr->int_num = 10;
  printf("info.int_num is %d", info.int_num);
  ptr->int_num = 20;
  printf("info.int_num1 is %d", info.int_num);
  
  return 0;
}*/

// Pointers + unions + functions

/*#include <stdio.h>
#include <string.h>

union id {
  int id_num;
  char name[20]; 
};

void set_id (union id *item);
void show_id (union id item);

int main() {  
  union id item;
  
  set_id(&item);  
  show_id(item);

  return 0;
}

void set_id(union id *item) {
    item->id_num = 42;
}

void show_id(union id item) {
    printf("ID is %d", item.id_num);
}*/

//Array + union:

/*#include <stdio.h>

union val {
  int int_num;
  float fl_num;
  char str[20]; 
};

int main() {  
  union val nums[10];
  int k;
  
  // create an array of ints 
  for (k = 0; k < 10; k++) {
    nums[k].int_num = k;
  }
  
  // display array values 
  for (k = 0; k < 10; k++) {
    printf("%d ", nums[k].int_num);
  }
  
  return 0;
}*/

//An array is a data structure that stores collection values that are all the same type. Arrays of unions allow storing values of different types

/*#include <stdio.h>

union type {
  int i_val;
  float f_val;
  char ch_val;
};

int main() {
  union type arr[3];
  arr[0].i_val = 42;
  arr[1].f_val = 3.14;
  arr[2].ch_val = 'x';
  printf("1st element is %d, 2nd is %f, and the 3rd is %c", arr[0].i_val, arr[1].f_val, arr[2].ch_val);
  
  return 0;
}*/

//Memory management......................................................................................................................

//malloc()

/*#include <stdio.h>
#include <stdlib.h>
int main() {
  int *ptr;
  printf("%d\n",sizeof(*ptr));
  ptr = malloc(10*sizeof(*ptr));  // a block of 10 ints 
  if (ptr != NULL) {
    *(ptr+2) = 50;  // assign 50 to third int 
  }
  printf("3rd elem equals to %d \n", *(ptr + 2));

  for(int i=0;i<10;i++)
  {
    printf("%d \t",*(ptr+i));
  }
  //free();
   for(int i=0;i<10;i++)
  {
    printf("%d \t",*(ptr+i));
  }
  return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>

int main() {  
  int *ptr;
  ptr = malloc(10*sizeof(*ptr));  // a block of 10 ints 
  if (ptr != NULL)
    *(ptr+2) = 50;  // assign 50 to third int 
  printf("%d\n", *(ptr+2));  // 50 

  free(ptr);

  return 0;
}*/

//calloc().............................

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int num;
  char *info;
} record;

int main() {
  record *recs;
  int num_recs = 2;
  int k;
  char str[ ] = "This is information";

  recs = calloc(num_recs, sizeof(record));
  if (recs != NULL) {
    for (k = 0; k < num_recs; k++) {
      (recs+k)->num = k;
      (recs+k)->info = malloc(sizeof(str));
      strcpy((recs+k)->info, str);
    }
  }

  for (k = 0; k < num_recs; k++) {
    printf("%d\t%s\n", (recs+k)->num, (recs+k)->info);
  }

  return 0;
}*/

//realloc()...................

/*#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr;
  ptr = malloc(10*sizeof(*ptr));  // a block of 10 ints 
  if (ptr != NULL) {
    *(ptr+2) = 50;  // assign 50 to third int 
  }
  ptr = realloc(ptr, 100*sizeof(*ptr)); //100 ints
  *(ptr+30) = 75;
  printf("%d %d", *(ptr+2), *(ptr+30));

  return 0;
}*/


// string using malloc()
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str20[20];
  char *str = NULL;

  strcpy(str20, "12345");
  printf("str20 size: %d\n", sizeof(str20));
  printf("str20 length: %d\n", strlen(str20));
  str = malloc(strlen(str20)+1); // make room for \0 
  strcpy(str, str20);
  printf("%s", str);

  return 0;
}*/

// dynamic Arrays........................................................


/*#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *elements; // whenever assigning malloc or calloc for memory
  int size;
  int cap;
} dyn_array;

int main() {
  dyn_array arr;
  int i;

  // initialize array 
  arr.size = 0;
  arr.elements = calloc(1, sizeof(*arr.elements));
  printf("size1: %d\n",sizeof(arr.elements));
  arr.cap = 1;  // room for 1 element 

  // expand by 5 more elements 
  arr.elements = realloc(arr.elements, (5 + arr.cap)*sizeof(*arr.elements));
   printf("size2: %d\n",sizeof(arr.elements));
  if (arr.elements != NULL)
    arr.cap += 5; // increase capacity 

  // add an element and increase size   
  if (arr.size < arr.cap) {
    arr.elements[arr.size] = 50; // add element to array 
    arr.size++;
  }
  else
    printf("Need to expand array.");

  // display array elements 
  for (i = 0; i < arr.cap; i++)
    printf("Element %d: %d\n", i, arr.elements[ i ]);

  return 0;
}*/

//file handling.......................................................................................................

/*#include <stdio.h>

int main() {  
  FILE *fptr;
  
  fptr = fopen("myfile.txt", "w");
  if (fptr == NULL) {
    printf("Error opening file.");
    return -1;
  }
  fclose(fptr);
  return 0;
}*/

#include <stdio.h>

int main() {
  FILE *fptr;
  int arr[10];
  int x[10];
  int k;

  /* generate array of numbers */
  for (k = 0; k < 10; k++)
    arr[k] = k;

  /* write array to file */
  fptr = fopen("datafile.bin", "wb");
  fwrite(arr, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fptr);
  fclose(fptr);

  /* read array from file */
  fptr = fopen("datafile.bin", "rb");
  fread(x, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fptr);
  fclose(fptr);

  /* print array */
  for (k = 0; k < 10; k++)
    printf("%d", x[k]);
  return 0;
}












