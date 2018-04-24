/* Author : Rohan Verma
   Implementation : Trie
   */



#include <bits/stdc++.h>

 #define alpha(a) a-'a'
 #define beta(a)


  using namespace std;
 struct trie_node{
struct trie_node *child[26];
bool end;
 };




trie_node *getNode(void)
{
    trie_node *pNode = NULL;

    pNode = (trie_node *)malloc(sizeof(trie_node));

    if( pNode )
    {
        int i;

        pNode->end = false;

        for(i = 0; i < 26; i++)
        {
            pNode->child[i] = NULL;
        }
    }
    return pNode;
}



void insert(struct trie_node *tn,char *a){
    int i=0;
     trie_node *crawl;

    crawl = (struct trie_node*)malloc(sizeof(struct trie_node));
    crawl = tn;

    while(i!=strlen(a)){
      if(!crawl->child[alpha(a[i])])
        crawl->child[alpha(a[i])] = getNode();

        crawl = crawl->child[alpha(a[i])];

        i++;
    }
    crawl->end = true;

}

void find(struct trie_node *tn , const char *a){

	    int i=0;
	struct trie_node *crawl;


    crawl = (struct trie_node*)malloc(sizeof(struct trie_node));
    crawl = tn;


    while(i<=strlen(a)-1){
      if(!crawl->child[alpha(a[i])]){
	  break;
	}else{
       crawl = crawl->child[alpha(a[i])] ;
        i++;
    }
    }
     if(crawl->end)
     	printf("%s\n",a);
     else
     	printf("%s\n","Not Found");

}


   int main(int argc, char const *argv[])
   {

   	    char a[] = "mahaan";
   	    char a1[] = "mahima";
   	    struct trie_node *tn;
        tn = getNode();

   	    ios_base::sync_with_stdio(0);


   	 insert(tn,a);insert(tn,a1);


	 find(tn,"mahaan");
   find(tn,"mahima");

   	return 0;
   }
