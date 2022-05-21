#include "header.h"


int test_clavier_suppr(int compteur, char pseudo[15],BITMAP*page,FONT* maPolice)
{
    if(key[KEY_BACKSPACE])
    {
        compteur--;
        pseudo[compteur]=' ';
        rest(200);
    }
    return compteur;
}

int test_clavier_entree(char pseudo[15],int boule)
{
    if(key[KEY_ENTER])
    {
        if(pseudo[0]==' ')
        {
            boule=0;
            rest(200);

        }
        if(pseudo[0]!=' ')
        {
            boule=1;
            rest(200);

        }
    }
    return boule;
}


int test_clavierA(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_Q])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierW(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_Z])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierZ(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_W])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierE(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_E])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierR(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_R])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierT(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_T])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierY(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_Y])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierU(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_U])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierI(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_I])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierO(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_O])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierP(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_P])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierQ(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_A])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierD(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_D])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierF(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_F])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierG(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_G])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierH(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_H])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}

int test_clavierJ(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_J])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierK(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_K])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierL(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_L])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierS(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_S])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}
int test_clavierM(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_SEMICOLON])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}

int test_clavierX(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_X])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}

int test_clavierC(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_C])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}

int test_clavierV(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_V])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}

int test_clavierB(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_B])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}

int test_clavierN(int compteur,char pseudo[15],char lettre)
{
    if(key[KEY_N])
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);
    }
    return compteur;
}




int test_clique(int destx, int desty, int longueur, int hauteur,char lettre,int compteur,char pseudo[15])
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur)&&(mouse_b && 1))
    {
        pseudo[compteur]=lettre;
        compteur++;
        rest(200);

    }
    return compteur;

}

int test_clique_Entree(int destx, int desty, int longueur, int hauteur,int boule,char pseudo[15])
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur)&&(mouse_b && 1))
    {
        if(pseudo[0]==' ')
        {
            boule=0;
            rest(200);

        }
        if(pseudo[0]!=' ')
        {
            boule=1;
            rest(200);

        }

    }
    return boule;


}

int test_clique_Suppr(int destx, int desty, int longueur, int hauteur,int compteur,char pseudo[15])
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur)&&(mouse_b && 1))
    {
        compteur--;
        pseudo[compteur]=' ';
        rest(200);

    }
    return compteur;


}

void Saisir_nom(char nom_joueur[15], BITMAP* page)
{
    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);
    int arret=0;
    char pseudo[15];
    int compteur=0;

    for (int i=0; i<15; i++)
    {
        pseudo[i]=' ';
    }

    char Al='A';
    char Bl='B';
    char Cl='C';
    char Dl='D';
    char El='E';
    char Fl='F';
    char Gl='G';
    char Hl='H';
    char Il='I';
    char Jl='J';
    char Kl='K';
    char Ll='L';
    char Ml='M';
    char Nl='N';
    char Ol='O';
    char Pl='P';
    char Ql='Q';
    char Rl='R';
    char Sl='S';
    char Tl='T';
    char Ul='U';
    char Vl='V';
    char Wl='W';
    char Xl='X';
    char Yl='Y';
    char Zl='Z';

    BITMAP*A;
    BITMAP*AInv;
    BITMAP*B;
    BITMAP*BInv;
    BITMAP*C;
    BITMAP*CInv;
    BITMAP*E;
    BITMAP*EInv;
    BITMAP*Z;
    BITMAP*ZInv;
    BITMAP*D;
    BITMAP*DInv;
    BITMAP*F;
    BITMAP*FInv;
    BITMAP*G;
    BITMAP*GInv;
    BITMAP*H;
    BITMAP*HInv;
    BITMAP*I;
    BITMAP*IInv;
    BITMAP*J;
    BITMAP*JInv;
    BITMAP*K;
    BITMAP*KInv;
    BITMAP*L;
    BITMAP*LInv;
    BITMAP*M;
    BITMAP*MInv;
    BITMAP*N;
    BITMAP*NInv;
    BITMAP*O;
    BITMAP*OInv;
    BITMAP*P;
    BITMAP*PInv;
    BITMAP*Q;
    BITMAP*QInv;
    BITMAP*R;
    BITMAP*RInv;
    BITMAP*S;
    BITMAP*SInv;
    BITMAP*T;
    BITMAP*TInv;
    BITMAP*U;
    BITMAP*UInv;
    BITMAP*V;
    BITMAP*VInv;
    BITMAP*W;
    BITMAP*WInv;
    BITMAP*X;
    BITMAP*XInv;
    BITMAP*Y;
    BITMAP*YInv;
    BITMAP*Suppr;
    BITMAP*SupprInv;
    BITMAP*Entree;
    BITMAP*EntreeInv;
    BITMAP*fondMenu;
    BITMAP*choixpseudo;
    BITMAP*barreNom;

    makecol(255, 0, 255);
    fondMenu=load_bitmap("fond/fondMenu.bmp",NULL);
    //logo=load_bitmap("logo_pokemon_bien.bmp",NULL);
    choixpseudo=load_bitmap("clavier/choixpseudo.bmp",NULL);
    barreNom=load_bitmap("clavier/barreNom.bmp",NULL);
    A=load_bitmap("clavier/A.bmp",NULL);
    AInv=load_bitmap("clavier/AInv.bmp",NULL);
    Z=load_bitmap("clavier/Z.bmp",NULL);
    ZInv=load_bitmap("clavier/ZInv.bmp",NULL);
    E=load_bitmap("clavier/E.bmp",NULL);
    EInv=load_bitmap("clavier/EInv.bmp",NULL);
    B=load_bitmap("clavier/B.bmp",NULL);
    BInv=load_bitmap("clavier/BInv.bmp",NULL);
    C=load_bitmap("clavier/C.bmp",NULL);
    CInv=load_bitmap("clavier/CInv.bmp",NULL);
    D=load_bitmap("clavier/D.bmp",NULL);
    DInv=load_bitmap("clavier/DInv.bmp",NULL);
    F=load_bitmap("clavier/F.bmp",NULL);
    FInv=load_bitmap("clavier/FInv.bmp",NULL);
    G=load_bitmap("clavier/G.bmp",NULL);
    GInv=load_bitmap("clavier/GInv.bmp",NULL);
    H=load_bitmap("clavier/H.bmp",NULL);
    HInv=load_bitmap("clavier/HInv.bmp",NULL);
    I=load_bitmap("clavier/I.bmp",NULL);
    IInv=load_bitmap("clavier/IInv.bmp",NULL);
    J=load_bitmap("clavier/J.bmp",NULL);
    JInv=load_bitmap("clavier/JInv.bmp",NULL);
    K=load_bitmap("clavier/K.bmp",NULL);
    KInv=load_bitmap("clavier/KInv.bmp",NULL);
    L=load_bitmap("clavier/L.bmp",NULL);
    LInv=load_bitmap("clavier/LInv.bmp",NULL);
    M=load_bitmap("clavier/M.bmp",NULL);
    MInv=load_bitmap("clavier/MInv.bmp",NULL);
    N=load_bitmap("clavier/N.bmp",NULL);
    NInv=load_bitmap("clavier/NInv.bmp",NULL);
    O=load_bitmap("clavier/O.bmp",NULL);
    OInv=load_bitmap("clavier/OInv.bmp",NULL);
    P=load_bitmap("clavier/P.bmp",NULL);
    PInv=load_bitmap("clavier/PInv.bmp",NULL);
    Q=load_bitmap("clavier/Q.bmp",NULL);
    QInv=load_bitmap("clavier/QInv.bmp",NULL);
    R=load_bitmap("clavier/R.bmp",NULL);
    RInv=load_bitmap("clavier/RInv.bmp",NULL);
    S=load_bitmap("clavier/S.bmp",NULL);
    SInv=load_bitmap("clavier/SInv.bmp",NULL);
    T=load_bitmap("clavier/T.bmp",NULL);
    TInv=load_bitmap("clavier/TInv.bmp",NULL);
    U=load_bitmap("clavier/U.bmp",NULL);
    UInv=load_bitmap("clavier/UInv.bmp",NULL);
    V=load_bitmap("clavier/V.bmp",NULL);
    VInv=load_bitmap("clavier/VInv.bmp",NULL);
    W=load_bitmap("clavier/W.bmp",NULL);
    WInv=load_bitmap("clavier/WInv.bmp",NULL);
    X=load_bitmap("clavier/X.bmp",NULL);
    XInv=load_bitmap("clavier/XInv.bmp",NULL);
    Y=load_bitmap("clavier/Y.bmp",NULL);
    YInv=load_bitmap("clavier/YInv.bmp",NULL);
    Suppr=load_bitmap("clavier/Suppr.bmp",NULL);
    SupprInv=load_bitmap("clavier/SupprInv.bmp",NULL);
    Entree=load_bitmap("clavier/Entree.bmp",NULL);
    EntreeInv=load_bitmap("clavier/EntreeInv.bmp",NULL);

    while(arret==0)
    {
        clear_bitmap(page);
        blit(fondMenu,page,0,0,0,0,1200,711);
        masked_blit(barreNom,page,0,0,195,474,1200,711);
        //masked_blit(logo,page,0,0,300,0,1200,711);
        masked_blit(choixpseudo,page,0,0,160,100,1200,711);
        blit(A,page,0,0,195,250,1200,711);
        blit(Z,page,0,0,270,250,1200,711);
        blit(E,page,0,0,345,250,1200,711);
        blit(R,page,0,0,420,250,1200,711);
        blit(T,page,0,0,495,250,1200,711);
        blit(Y,page,0,0,570,250,1200,711);
        blit(U,page,0,0,645,250,1200,711);
        blit(I,page,0,0,720,250,1200,711);
        blit(O,page,0,0,795,250,1200,711);
        blit(P,page,0,0,870,250,1200,711);
        blit(Q,page,0,0,195,325,1200,711);
        blit(S,page,0,0,270,325,1200,711);
        blit(D,page,0,0,345,325,1200,711);
        blit(F,page,0,0,420,325,1200,711);
        blit(G,page,0,0,495,325,1200,711);
        blit(H,page,0,0,570,325,1200,711);
        blit(J,page,0,0,645,325,1200,711);
        blit(K,page,0,0,720,325,1200,711);
        blit(L,page,0,0,795,325,1200,711);
        blit(M,page,0,0,870,325,1200,711);
        blit(W,page,0,0,195,400,1200,711);
        blit(X,page,0,0,270,400,1200,711);
        blit(C,page,0,0,345,400,1200,711);
        blit(V,page,0,0,420,400,1200,711);
        blit(V,page,0,0,495,400,1200,711);
        blit(W,page,0,0,570,400,1200,711);
        blit(Entree,page,0,0,645,400,1200,711);
        blit(Suppr,page,0,0,795,400,1200,711);


        AffichageBouton(A,AInv,page,0,0,195,250,75,75);
        AffichageBouton(Z,ZInv,page,0,0,270,250,75,75);
        AffichageBouton(E,EInv,page,0,0,345,250,75,75);
        AffichageBouton(R,RInv,page,0,0,420,250,75,75);
        AffichageBouton(T,TInv,page,0,0,495,250,75,75);
        AffichageBouton(Y,YInv,page,0,0,570,250,75,75);
        AffichageBouton(U,UInv,page,0,0,645,250,75,75);
        AffichageBouton(I,IInv,page,0,0,720,250,75,75);
        AffichageBouton(O,OInv,page,0,0,795,250,75,75);
        AffichageBouton(P,PInv,page,0,0,870,250,75,75);
        AffichageBouton(Q,QInv,page,0,0,195,325,75,75);
        AffichageBouton(S,SInv,page,0,0,270,325,75,75);
        AffichageBouton(D,DInv,page,0,0,345,325,75,75);
        AffichageBouton(F,FInv,page,0,0,420,325,75,75);
        AffichageBouton(G,GInv,page,0,0,495,325,75,75);
        AffichageBouton(H,HInv,page,0,0,570,325,75,75);
        AffichageBouton(J,JInv,page,0,0,645,325,75,75);
        AffichageBouton(K,KInv,page,0,0,720,325,75,75);
        AffichageBouton(L,LInv,page,0,0,795,325,75,75);
        AffichageBouton(M,MInv,page,0,0,870,325,75,75);
        AffichageBouton(W,WInv,page,0,0,195,400,75,75);
        AffichageBouton(X,XInv,page,0,0,270,400,75,75);
        AffichageBouton(C,CInv,page,0,0,345,400,75,75);
        AffichageBouton(V,VInv,page,0,0,420,400,75,75);
        AffichageBouton(B,BInv,page,0,0,495,400,75,75);
        AffichageBouton(N,NInv,page,0,0,570,400,75,75);
        AffichageBouton(Entree,EntreeInv,page,0,0,645,400,150,75);
        AffichageBouton(Suppr,SupprInv,page,0,0,795,400,150,75);


        compteur =test_clique(195,250,75,75,Al,compteur,pseudo);
        compteur =test_clique(270,250,75,75,Zl,compteur,pseudo);
        compteur =test_clique(345,250,75,75,El,compteur,pseudo);
        compteur =test_clique(420,250,75,75,Rl,compteur,pseudo);
        compteur =test_clique(495,250,75,75,Tl,compteur,pseudo);
        compteur =test_clique(570,250,75,75,Yl,compteur,pseudo);
        compteur =test_clique(645,250,75,75,Ul,compteur,pseudo);
        compteur =test_clique(720,250,75,75,Il,compteur,pseudo);
        compteur =test_clique(795,250,75,75,Ol,compteur,pseudo);
        compteur =test_clique(870,250,75,75,Pl,compteur,pseudo);
        compteur =test_clique(195,325,75,75,Ql,compteur,pseudo);
        compteur =test_clique(270,325,75,75,Sl,compteur,pseudo);
        compteur =test_clique(345,325,75,75,Dl,compteur,pseudo);
        compteur =test_clique(420,325,75,75,Fl,compteur,pseudo);
        compteur =test_clique(495,325,75,75,Gl,compteur,pseudo);
        compteur =test_clique(570,325,75,75,Hl,compteur,pseudo);
        compteur =test_clique(645,325,75,75,Jl,compteur,pseudo);
        compteur =test_clique(720,325,75,75,Kl,compteur,pseudo);
        compteur =test_clique(795,325,75,75,Ll,compteur,pseudo);
        compteur =test_clique(870,325,75,75,Ml,compteur,pseudo);
        compteur =test_clique(195,400,75,75,Wl,compteur,pseudo);
        compteur =test_clique(270,400,75,75,Xl,compteur,pseudo);
        compteur =test_clique(345,400,75,75,Cl,compteur,pseudo);
        compteur =test_clique(420,400,75,75,Vl,compteur,pseudo);
        compteur =test_clique(495,400,75,75,Bl,compteur,pseudo);
        compteur =test_clique(570,400,75,75,Nl,compteur,pseudo);
        compteur =test_clavierA(compteur,pseudo,Al);
        compteur =test_clavierZ(compteur,pseudo,Zl);
        compteur =test_clavierE(compteur,pseudo,El);
        compteur =test_clavierR(compteur,pseudo,Rl);
        compteur =test_clavierT(compteur,pseudo,Tl);
        compteur =test_clavierY(compteur,pseudo,Yl);
        compteur =test_clavierM(compteur,pseudo,Ml);
        compteur =test_clavierU(compteur,pseudo,Ul);
        compteur =test_clavierI(compteur,pseudo,Il);
        compteur =test_clavierO(compteur,pseudo,Ol);
        compteur =test_clavierP(compteur,pseudo,Pl);
        compteur =test_clavierQ(compteur,pseudo,Ql);
        compteur =test_clavierS(compteur,pseudo,Sl);
        compteur =test_clavierD(compteur,pseudo,Dl);
        compteur =test_clavierF(compteur,pseudo,Fl);
        compteur =test_clavierG(compteur,pseudo,Gl);
        compteur =test_clavierH(compteur,pseudo,Hl);
        compteur =test_clavierJ(compteur,pseudo,Jl);
        compteur =test_clavierK(compteur,pseudo,Kl);
        compteur =test_clavierL(compteur,pseudo,Ll);
        compteur =test_clavierX(compteur,pseudo,Xl);
        compteur =test_clavierC(compteur,pseudo,Cl);
        compteur =test_clavierV(compteur,pseudo,Vl);
        compteur =test_clavierB(compteur,pseudo,Bl);
        compteur =test_clavierN(compteur,pseudo,Nl);
        compteur =test_clavierW(compteur,pseudo,Wl);
        arret=test_clavier_entree(pseudo,arret);
        compteur=test_clavier_suppr(compteur,pseudo,page,maPolice);

        arret=test_clique_Entree(645,400,150,75,arret,pseudo);
        compteur=test_clique_Suppr(795,400,150,75,compteur,pseudo);
        for (int v=0; v<15; v++)
        {
            nom_joueur[v]=pseudo[v];
        }


        for(int y=0; y<15; y++)
        {
            textprintf_ex(page, maPolice, 210+25*y, 460, makecol(255,255, 0), -1,"%c",nom_joueur[y]);

        }

        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);



    }
    blit(fondMenu,page,0,0,0,0,1200,711);
    textprintf_ex(page, maPolice, 340, 300, makecol(255, 255, 0), -1," Tu es ");
    for(int z=0; z<15; z++)
    {
        textprintf_ex(page, maPolice, 515+30*z, 300, makecol(255, 255, 0), -1,"%c",nom_joueur[z]);

    }


    show_mouse(page);
    blit(page,screen,0,0,0,0,1200,711);
    rest(1000);


}


