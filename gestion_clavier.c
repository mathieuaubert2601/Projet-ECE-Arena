#include "header.h"


/*void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur)
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur))
    {
        masked_blit(boutonInv,page,sourcex,sourcey,destx,desty,longueur,hauteur);

    }
    else
        masked_blit(bouton,page,sourcex,sourcey,destx,desty,longueur,hauteur);
}*/

int test_clique(int destx, int desty, int longueur, int hauteur,char lettre,int compteur,char pseudo[15])
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur)&&(mouse_b && 1))
    {
        //masked_blit(boutonInv,page,sourcex,sourcey,destx,desty,longueur,hauteur);
        pseudo[compteur]=lettre;
        compteur++;
        rest(100);

    }
    return compteur;

}

int test_clique_Entree(int destx, int desty, int longueur, int hauteur,int boule)
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur)&&(mouse_b && 1))
    {
        boule=1;

        rest(100);

    }
    return boule;

}

int test_clique_Suppr(int destx, int desty, int longueur, int hauteur,int compteur,char pseudo[15])
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur)&&(mouse_b && 1))
    {
        compteur--;
        pseudo[compteur]=' ';
        rest(100);

    }
    return compteur;


}

void Saisir_nom(t_joueur* lejoueur)
{

    int arret=0;
    char pseudo[15];
    int compteur=0;

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
    allegro_init();
    install_keyboard();
    install_mouse();
    /*for(int i=0;i<15;i++)
    {
         pseudo[i]=' ';

    }*/



    //al_init_font_addon();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,711,0,0)!=0){
        allegro_message("probleme gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
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
    BITMAP*clavier;
    BITMAP*page;
    BITMAP*fondMenu;
    BITMAP*logo;
    BITMAP*phrase1;
    BITMAP*choixpseudo;
    BITMAP*barreNom;

    makecol(255, 0, 255);
    clavier=load_bitmap("clavier.bmp",NULL);
    page=create_bitmap(SCREEN_W,SCREEN_H);
    fondMenu=load_bitmap("fondMenu.bmp",NULL);
    logo=load_bitmap("logo_pokemon_bien.bmp",NULL);
    choixpseudo=load_bitmap("choixpseudo.bmp",NULL);
    barreNom=load_bitmap("barreNom.bmp",NULL);
    A=load_bitmap("A.bmp",NULL);
    AInv=load_bitmap("AInv.bmp",NULL);
    Z=load_bitmap("Z.bmp",NULL);
    ZInv=load_bitmap("ZInv.bmp",NULL);
    E=load_bitmap("E.bmp",NULL);
    EInv=load_bitmap("EInv.bmp",NULL);
    B=load_bitmap("B.bmp",NULL);
    BInv=load_bitmap("BInv.bmp",NULL);
    C=load_bitmap("C.bmp",NULL);
    CInv=load_bitmap("CInv.bmp",NULL);
    D=load_bitmap("D.bmp",NULL);
    DInv=load_bitmap("DInv.bmp",NULL);
    F=load_bitmap("F.bmp",NULL);
    FInv=load_bitmap("FInv.bmp",NULL);
    G=load_bitmap("G.bmp",NULL);
    GInv=load_bitmap("GInv.bmp",NULL);
    H=load_bitmap("H.bmp",NULL);
    HInv=load_bitmap("HInv.bmp",NULL);
    I=load_bitmap("I.bmp",NULL);
    IInv=load_bitmap("IInv.bmp",NULL);
    J=load_bitmap("J.bmp",NULL);
    JInv=load_bitmap("JInv.bmp",NULL);
    K=load_bitmap("K.bmp",NULL);
    KInv=load_bitmap("KInv.bmp",NULL);
    L=load_bitmap("L.bmp",NULL);
    LInv=load_bitmap("LInv.bmp",NULL);
    M=load_bitmap("M.bmp",NULL);
    MInv=load_bitmap("MInv.bmp",NULL);
    N=load_bitmap("N.bmp",NULL);
    NInv=load_bitmap("NInv.bmp",NULL);
    O=load_bitmap("O.bmp",NULL);
    OInv=load_bitmap("OInv.bmp",NULL);
    P=load_bitmap("P.bmp",NULL);
    PInv=load_bitmap("PInv.bmp",NULL);
    Q=load_bitmap("Q.bmp",NULL);
    QInv=load_bitmap("QInv.bmp",NULL);
    R=load_bitmap("R.bmp",NULL);
    RInv=load_bitmap("RInv.bmp",NULL);
    S=load_bitmap("S.bmp",NULL);
    SInv=load_bitmap("SInv.bmp",NULL);
    T=load_bitmap("T.bmp",NULL);
    TInv=load_bitmap("TInv.bmp",NULL);
    U=load_bitmap("U.bmp",NULL);
    UInv=load_bitmap("UInv.bmp",NULL);
    V=load_bitmap("V.bmp",NULL);
    VInv=load_bitmap("VInv.bmp",NULL);
    W=load_bitmap("W.bmp",NULL);
    WInv=load_bitmap("WInv.bmp",NULL);
    X=load_bitmap("X.bmp",NULL);
    XInv=load_bitmap("XInv.bmp",NULL);
    Y=load_bitmap("Y.bmp",NULL);
    YInv=load_bitmap("YInv.bmp",NULL);
    Suppr=load_bitmap("Suppr.bmp",NULL);
    SupprInv=load_bitmap("SupprInv.bmp",NULL);
    Entree=load_bitmap("Entree.bmp",NULL);
    EntreeInv=load_bitmap("EntreeInv.bmp",NULL);

    while(!key[KEY_ESC])
    {
        show_mouse(page);
        clear_bitmap(page);
        draw_sprite(page,fondMenu,0,0);
        //masked_blit(clavier,page,0,0,190,250,SCREEN_W,SCREEN_H);
        masked_blit(barreNom,page,0,0,195,474,SCREEN_W,SCREEN_H);
        masked_blit(logo,page,0,0,300,0,SCREEN_W,SCREEN_H);
        masked_blit(choixpseudo,page,0,0,160,100,SCREEN_W,SCREEN_H);
        blit(A,page,0,0,195,250,SCREEN_W,SCREEN_H);
        blit(Z,page,0,0,270,250,SCREEN_W,SCREEN_H);
        blit(E,page,0,0,345,250,SCREEN_W,SCREEN_H);
        blit(R,page,0,0,420,250,SCREEN_W,SCREEN_H);
        blit(T,page,0,0,495,250,SCREEN_W,SCREEN_H);
        blit(Y,page,0,0,570,250,SCREEN_W,SCREEN_H);
        blit(U,page,0,0,645,250,SCREEN_W,SCREEN_H);
        blit(I,page,0,0,720,250,SCREEN_W,SCREEN_H);
        blit(O,page,0,0,795,250,SCREEN_W,SCREEN_H);
        blit(P,page,0,0,870,250,SCREEN_W,SCREEN_H);
        blit(Q,page,0,0,195,325,SCREEN_W,SCREEN_H);
        blit(S,page,0,0,270,325,SCREEN_W,SCREEN_H);
        blit(D,page,0,0,345,325,SCREEN_W,SCREEN_H);
        blit(F,page,0,0,420,325,SCREEN_W,SCREEN_H);
        blit(G,page,0,0,495,325,SCREEN_W,SCREEN_H);
        blit(H,page,0,0,570,325,SCREEN_W,SCREEN_H);
        blit(J,page,0,0,645,325,SCREEN_W,SCREEN_H);
        blit(K,page,0,0,720,325,SCREEN_W,SCREEN_H);
        blit(L,page,0,0,795,325,SCREEN_W,SCREEN_H);
        blit(M,page,0,0,870,325,SCREEN_W,SCREEN_H);
        blit(W,page,0,0,195,400,SCREEN_W,SCREEN_H);
        blit(X,page,0,0,270,400,SCREEN_W,SCREEN_H);
        blit(C,page,0,0,345,400,SCREEN_W,SCREEN_H);
        blit(V,page,0,0,420,400,SCREEN_W,SCREEN_H);
        blit(V,page,0,0,495,400,SCREEN_W,SCREEN_H);
        blit(W,page,0,0,570,400,SCREEN_W,SCREEN_H);
        blit(Entree,page,0,0,645,400,SCREEN_W,SCREEN_H);
        blit(Suppr,page,0,0,795,400,SCREEN_W,SCREEN_H);


        if(arret==0)
        {
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

        arret=test_clique_Entree(645,400,150,75,arret);
        compteur=test_clique_Suppr(795,400,150,75,compteur,pseudo);
        for (int v=0;v<15;v++)
        {
            lejoueur->pseudo[v]=pseudo[v];
        }


        for(int y=0;y<15;y++)
        {
            textprintf_ex(page, font, 195+10*y, 474, makecol(0, 0, 0), -1,"%c",lejoueur->pseudo[y]);



        }

        }
        else{

            draw_sprite(page,fondMenu,0,0);
            textprintf_ex(page, font, 400, 300, makecol(0, 0, 0), -1," Tu es");
            for(int z=0;z<15;z++)
            {
                textprintf_ex(page, font, 450+10*z, 300, makecol(0, 0, 0), -1,"%c",lejoueur->pseudo[z]);

            }
            textprintf_ex(page, font, 500, 300, makecol(0, 0, 0), -1,"!");

            show_mouse(page);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);




        }




        show_mouse(page);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);





    }


}

