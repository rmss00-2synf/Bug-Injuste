#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1
int Contains(char *Ph1, char *Ph2)
{
    if (strlen(Ph1) < strlen(Ph2))
        return 0;
    char *p, q[100];
    int i;
    for (p = Ph1; p < Ph1 + strlen(Ph1) - strlen(Ph2); p++)
    {
        strncpy(q, p, strlen(Ph2));
        if (!strcmp(q, Ph2))
            return 1;
        q[0] = '\0';
    }
    return 0;
}

// 2

struct cellule
{
    char Val;
    struct cellule *Next;
};

typedef struct cellule *Liste;

Liste createNode(char x)
{
    Liste New = malloc(sizeof(Liste));
    New->Val = x;
    New->Next = NULL;
    return New;
}

Liste pushBack(Liste L, char x)
{
    Liste New = createNode(x), p;
    if (!L)
        return New;
    for (p = L; p->Next; p = p->Next)
        ;
    p->Next = New;
    return L;
}

Liste lire(char *c)
{
    Liste L = NULL;
    char *p;
    for (p = c; *p; p++)
        L = pushBack(L, *p);
    return L;
}

int EstDans(Liste L, char x)
{
    for (; L; L = L->Next)
        if (L->Val == x)
            return 1;

    return 0;
}

Liste Difference(Liste L1, Liste L2)
{
    Liste L = NULL, p;
    for (p = L1; p; p = p->Next)
    {
        if (!EstDans(L2, p->Val) && !EstDans(L, p->Val))
            L = pushBack(L, p->Val);
    }
    return L;
}

int lenghList(Liste L)
{
    int i = 0;
    for (; L; L = L->Next)
        i++;
    return i;
}

char *Commun(Liste L1, Liste L2)
{
    char *p, *q;
    int i;
    Liste L = NULL, l;
    l = Difference(L1, L2);
    L = Difference(L1, l);
    if (!L)
        return NULL;
    p = (char *)malloc((lenghList(L) + 1) * sizeof(char));
    for (i = 0; L; L = L->Next, i++)
        *(p + i) = L->Val;
    *(p + i) = '\0';
    return p;
}

char *ListToChaine(Liste L)
{
    if (!L)
        return NULL;
    char *p, *q;
    int i;
    p = (char *)malloc((lenghList(L) + 1) * sizeof(char));
    for (i = 0; L; L = L->Next, i++)
        *(p + i) = L->Val;
    *(p + i) = '\0';
    return p;
}

int NoDuplicates(Liste L)
{
    Liste p;
    if (L)
        for (; L->Next; L = L->Next)
        {
            p = L->Next;
            if (EstDans(p, L->Val))
                return 0;
        }
    return 1;
}

void AfficheListe(Liste L)
{
    for (; L; L = L->Next)
    {
        printf("[%c]-> ", L->Val);
    }
    puts(" NULL");
    puts("=====================================================================");
}

int main(int argc, char const *argv[])
{
    // if (Contains("SaSalmi Salman !", "sal"))
    // {
    //     puts("True");
    // }
    // else
    //     puts("False");
    Liste L1 = NULL, L2 = NULL;
    L1 = lire("SaSalmi Salman ! ");
    L2 = lire("Salma");
    // AfficheListe(L1);
    // AfficheListe(L2);
    puts(ListToChaine(L1));
    AfficheListe(Difference(L2, L1));
    return 0;
}
