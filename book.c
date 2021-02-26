#include<stdio.h>
#include<stdlib.h>
struct book
{
	char title[20];
	char author[20];
	int id;
	int price;
};
struct node 
{
	struct book *b;
	struct node *link;
};
struct node *start=NULL;
struct node* createnode()
{
	struct node *n;
	
	n= (struct node*)malloc(sizeof(struct node));
	n->b=(struct book*)malloc(sizeof(struct book));
	return(n);
}
void insertnode()
{
	struct node *n,*t;
	int x;
	n= createnode();
	printf("enter book name");
	scanf("%s",&n->b->title);
	printf("enter book author name");
	scanf("%s",&n->b->author);
	x=validId();
	n->b->id=x;
	printf("enter book price");
	scanf("%d",&n->b->price);
	n->link=NULL;

	if(start==NULL)
	start=n;
	else
	{ t=start;
	while(t->link!=NULL)
	{
		t=t->link;
	
	}
		t->link=n;
	}
}

int validId()
{
		int id,k;
		struct node *t;
		printf("enter book id");
		scanf("%d",&id);
		if(start==NULL)
		{
				return id;
			
	
		}
	else
	{ 
	t=start;
	while(t!=NULL)
	{
		if(t->b->id== id)
		{
			printf("enter valid id \n");
			k=validId();
			return k;
			
		}
		
		t=t->link;
		
	
	}
	return id;
	
	}
	 
	
	}
	
void deletenode()
{
		struct node *p;
		if(start==NULL)
		
			printf("list is empty");
			else
			{
				p=start;
				start=start->link;
				free(p);
			}
}
void display()
{
	struct node *x;
	if(start==NULL)
	printf("list is empty");
	else{
				x=start;
		while(x!=NULL)
		{
		        
				printf("  title->  %s", x->b->title);
				printf("\t\tauthor-> %s",x->b->author);
				printf("\t\t\t id-> %d",x->b->id);
				printf("\t\tprice->  %d" ,x->b->price); 
		         printf("\n");
					x=x->link;
		}
	}
}

void bookid()
{
	int id;
	struct node *n ;
	printf("enter your book id");
	scanf("%d",&id);
	
	if(start==NULL)
	{
		printf("sorry book list is empty");
	}
	else
{
	n=start;
	while(n!=NULL)
	{
		if(n->b->id == id)
		{
				printf("  title->  %s", n->b->title);
				printf("\t\tauthor-> %s",n->b->author);
				printf("\t\t\t \t id-> %d",n->b->id);
				printf("\t\tprice->  %d" ,n->b->price); 
		         printf("\n");
		          
		          break;
		}
		else{
			
			n=n->link;
		}
		
	}
	
}
}

 void reverselinklist()
 {
 	struct node *t1,*t2;
 	t1=t2=NULL;
 
 	if(start!=NULL)
 	{
 		t1=start;
 		t2=start->link;
 		start= start->link;
 		t2->link=NULL;
 		
 	
 	while(start!=NULL)
 	{
 		start=start->link;
 		t2->link=t1;
 		t1=t2;
 		t2=start;
 	
 	}
 	
 	}
 	
 	start=t1;

 
 }
int menu()
{
	int ch;
	printf("\n 1. add book");
	printf("\n 2.delete book");
	printf("\n3.view list");
	printf("\n 4. veiw book");
	printf("\n 5. reverse element");
	printf("\n 6. exit");
	printf("\nenter your choice");
	scanf("%d",&ch);
	return(ch);
}
int main()
{
	while(1)
	{
		switch(menu())
		{
			case 1: insertnode();
			break;
			case 2: deletenode(); 
			break;
			case 3: display();
			break;
			case 4: bookid();
			break;
			case 5: reverselinklist();
			break;
			case 6: exit(0);
			default: printf("enter valid choice");
		}
	}
}
		

	
				
					
						
				
				
				
			
		
		
		
		
	
	