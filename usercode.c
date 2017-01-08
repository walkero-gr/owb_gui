/*
**	User Code functions
*/

#include "includes.h"

void Window1_CloseWindow_Evt(void)
{
    CleanExit("JustExit");
}

void Menu_Quit1_MenuPick_Evt(void)
{
	CleanExit("JustExit");
}

void Window1_IconifyWindow_Evt(void)
{//test
	if(win4_opened) {
		Ep_CloseWindow_Window4();
	}
    RA_Iconify(obj[OID_WindowObject3]);
	win[WID_Window3] = NULL;
    RA_Iconify(obj[OID_WindowObject1]);
	win[WID_Window1] = NULL;
}

void Window1_UnIconifyWindow_Evt(void)
{

    win[WID_Window3] = RA_OpenWindow(obj[OID_WindowObject3]);
    win[WID_Window1] = RA_OpenWindow(obj[OID_WindowObject1]);
}

void Window4_CloseWindow_Evt(void)
{
	win4_opened=0;
	IIntuition->SetWindowAttrs(win[WID_Window1], WA_BusyPointer, FALSE, TAG_DONE);
	IIntuition->SetWindowAttrs(win[WID_Window3], WA_BusyPointer, FALSE, TAG_DONE);
	Ep_CloseWindow_Window4();
}

void Menu_Information1_MenuPick_Evt(void)
{
	IIntuition->IDoMethod(obj[OID_Inforequest1],RM_OPENREQ,NULL,win[WID_Window1],NULL,TAG_DONE);
}

void Menu_prefs_MenuPick_Evt(void)
{
    Ep_OpenWindow_Window2();
}

void Window2_CloseWindow_Evt(void)
{
    Ep_CloseWindow_Window2();
}

void Menuitem1_MenuPick_Evt(void)
{
	showpage("http://www.amigaworld.net");
}

void Menuitem2_MenuPick_Evt(void)
{
	showpage("http://www.amiga-news.de");
}

void Menuitem3_MenuPick_Evt(void)
{
	showpage("http://www.os4depot.net");
}

void Menuitem4_MenuPick_Evt(void)
{
	showpage("http://www.amigans.net");
}

void Menuitem5_MenuPick_Evt(void)
{
	showpage("http://www.amigahellas.gr");
}

void Menuitem6_MenuPick_Evt(void)
{
	showpage("http://utilitybase.com/");
}

void Button1_GadgetUp_Evt(void)
{
	showpage(var_homeurl);
}

void Button2_GadgetUp_Evt(void)
{   
	IIntuition->GetAttrs(gad[GID_String1],STRINGA_TextVal, &urllink, TAG_DONE);
	
    showpage(urllink);
}

void Button6_GadgetUp_Evt(void)
{	
    if (IExec->FindTask("OWB"))
    {
	    //IDOS->Execute("rx \"ADDRESS OWB GOBACK\"", 0, 0);
	    cmdline = IUtility->ASPrintf("rx \"ADDRESS OWB GOBACK\"");
	    if (IDOS->SystemTags(cmdline,
        	      SYS_Input,  ZERO,
        		  SYS_Output, NULL,
        		  SYS_Error,  ZERO,
        		  SYS_Asynch, TRUE,
        		  TAG_END
              )!=-1) {}
	    
    } else {
        IIntuition->SetGadgetAttrs(gad[GID_Button6],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button7],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button8],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
    }
}

void Button7_GadgetUp_Evt(void)
{
    if (IExec->FindTask("OWB"))
    {
	    IDOS->Execute("rx \"ADDRESS OWB GOFORWARD\"", 0, 0);
    } else {
        IIntuition->SetGadgetAttrs(gad[GID_Button6],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button7],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button8],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
    }
}

void Button8_GadgetUp_Evt(void)
{
    if (IExec->FindTask("OWB"))
    {
	    IDOS->Execute("rx \"ADDRESS OWB STOP\"", 0, 0);
    } else {
        IIntuition->SetGadgetAttrs(gad[GID_Button6],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button7],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button8],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
    }
}

void Button5_GadgetUp_Evt(void)
{
	IIntuition->GetAttrs(gad[GID_String4],STRINGA_TextVal, &urllink, TAG_DONE);
	if (IExec->FindTask("OWB"))
    {            		                                                          
		cmdline = IUtility->ASPrintf("rx rexx/googlesearch.rx %s", urllink);
		IDOS->Execute(cmdline, 0, 0);
    } else {
        cmdline = IUtility->ASPrintf("http://www.google.com/search?q=%s", urllink);
		showpage(cmdline);
    }      
}

void Button3_GadgetUp_Evt(void)
{
    WriteCFG();
    Ep_CloseWindow_Window2();
}

void showpage(char *textca)
{
    if (IExec->FindTask("OWB"))
    {
        IIntuition->SetGadgetAttrs(gad[GID_Button6],win[WID_Window1], NULL, GA_Disabled, FALSE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button7],win[WID_Window1], NULL, GA_Disabled, FALSE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button8],win[WID_Window1], NULL, GA_Disabled, FALSE, TAG_DONE);

        cmdline = IUtility->ASPrintf("rx \"ADDRESS OWB OPENURL '%s'\"", textca);
        IDOS->Execute(cmdline, 0, 0);
    } else {                
        cmdline = IUtility->ASPrintf("OWB >NIL: *>NIL: --width %s --height %s --depth %s --url %s", var_width, var_height, var_depth, textca);
        //BPTR OutPipe;
        //printf("%s\n", cmdline);

        //if((OutPipe = IDOS->Open("CON:////", MODE_NEWFILE)))
        //{
          if (IDOS->SystemTags(cmdline,
        	      SYS_Input,  ZERO,
        		  SYS_Output, NULL,
        		  SYS_Error,  ZERO,
        		  SYS_Asynch, TRUE,
                  NP_Name, "OWB",
        		  TAG_END
              )!=-1) {}

        //}   
        IIntuition->SetGadgetAttrs(gad[GID_Button6],win[WID_Window1], NULL, GA_Disabled, FALSE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button7],win[WID_Window1], NULL, GA_Disabled, FALSE, TAG_DONE);
        IIntuition->SetGadgetAttrs(gad[GID_Button8],win[WID_Window1], NULL, GA_Disabled, FALSE, TAG_DONE);

    }
}

BOOL WriteCFG(void)
{
    FILE *fp;
    BOOL ret=FALSE;

    IIntuition->GetAttrs(gad[GID_String2],STRINGA_TextVal, &var_width, TAG_DONE);
    IIntuition->GetAttrs(gad[GID_String3],STRINGA_TextVal, &var_height, TAG_DONE);
    IIntuition->GetAttrs(gad[GID_String5],STRINGA_TextVal, &var_homeurl, TAG_DONE);

    // Get the value of the chooser
    ULONG sel;
    struct Node *node, *succ;

    IIntuition->GetAttr(CHOOSER_Selected,gad[GID_Chooser1],&sel);
    IIntuition->GetAttr(CHOOSER_Labels,gad[GID_Chooser1],(ULONG *)&Ep_Chooser_depth_node);

    for (node = Ep_Chooser_depth_node->lh_Head; succ = node->ln_Succ; node = succ)
    {
        if (sel == 0)
        {
           IChooser->GetChooserNodeAttrs(node,CNA_Text,&var_depth,TAG_END);
           break;
        }
        sel --;
    }
    // End of getting the value of the chooser


    //Check the values the user gave
    if(atol(var_width) > 0) {      
    } else {
        strcpy(var_width, "320");
    }
    if(atol(var_height) > 0) {
    } else {
        strcpy(var_height, "240");
    }
    
    if(strlen(var_homeurl) == 0) {  
        IIntuition->SetGadgetAttrs(gad[GID_Button1],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
    } else {                           
        IIntuition->SetGadgetAttrs(gad[GID_Button1],win[WID_Window1], NULL, GA_Disabled, FALSE, TAG_DONE);
    }

    if(fp=fopen(CFG_FILE,"wb"))
    {
    	fprintf(fp,"width=%s\n", var_width);
    	fprintf(fp,"height=%s\n", var_height);
        fprintf(fp,"depth=%s\n", var_depth);
        fprintf(fp,"homeurl=%s\n", var_homeurl);

        fclose(fp);
    	ret=TRUE;
    }

    return(ret);
}

BOOL ReadCFG(void)
{
    BOOL ret=TRUE;
    FILE *in_file;  /* input file */
    /* character or EOF flag from input */
    char Line[100];
    char * pch;

	in_file = fopen(CFG_FILE, "r");
    if (in_file != NULL) {

   		while (1) {
        	if (!fgets (Line, 100, in_file)) break;

            Line[strlen(Line)-1]='\0';

            if (Line[0]=='#') continue;

            pch = strtok(Line,"=");

            if (!strcmp(pch, "width")) {
                pch = strtok(NULL,"=");
                if((pch != NULL) && (pch != '\0')) {
                    var_width=(char *)malloc(strlen(pch)+1);
                    strcpy(var_width, pch); 
                } else {
                    var_width=(char *)malloc(10);
                    strcpy(var_width, "640");
                }

                
            } else if (!strcmp(pch, "height")) {
                pch = strtok(NULL,"=");                                                  
                if((pch != NULL) && (pch != '\0')) {
                    var_height=(char *)malloc(strlen(pch)+1);
                    strcpy(var_height, pch);
                } else {
                    var_height=(char *)malloc(10);
                    strcpy(var_height, "480");
                }

    		} else if (!strcmp(pch, "depth")) {
                pch = strtok(NULL,"=");        
                if((pch != NULL) && (pch != '\0')) {
                    var_depth=(char *)malloc(strlen(pch)+1);
                    strcpy(var_depth, pch);
                } else {
                    var_depth=(char *)malloc(10);
                    strcpy(var_depth, "32");
                }

    		} else if (!strcmp(pch, "homeurl")) {
                pch = strtok(NULL,"=");
                if((pch != NULL) && (pch != '\0')) {
                    var_homeurl=(char *)malloc(strlen(pch)+1);
                    strcpy(var_homeurl, pch);
                } else {                 
                    //var_homeurl=(char *)malloc(30);
                    //strcpy(var_homeurl, "http://mail.yahoo.com");
				   
					IIntuition->SetGadgetAttrs(gad[GID_Button1],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
                }
    		}
        }
        fclose(in_file);
        
        if (!IExec->FindTask("OWB"))
        {
            IIntuition->SetGadgetAttrs(gad[GID_Button6],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
            IIntuition->SetGadgetAttrs(gad[GID_Button7],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
            IIntuition->SetGadgetAttrs(gad[GID_Button8],win[WID_Window1], NULL, GA_Disabled, TRUE, TAG_DONE);
        }

   } else {
       var_width=(char *)malloc(10);
       var_height=(char *)malloc(10);
       var_depth=(char *)malloc(10);
       var_homeurl=(char *)malloc(30);
       strcpy(var_width, "640");
       strcpy(var_height, "480");
       strcpy(var_depth, "32");
       strcpy(var_homeurl, "http://mail.yahoo.com");
   }             
  
   IIntuition->SetAttrs(gad[GID_String2],STRINGA_TextVal, var_width, TAG_DONE);
   IIntuition->SetAttrs(gad[GID_String3],STRINGA_TextVal, var_height, TAG_DONE);
   IIntuition->SetAttrs(gad[GID_String5],STRINGA_TextVal, var_homeurl, TAG_DONE);

   if(strcmp(var_depth, "32") == 0) {
       IIntuition->SetAttrs(gad[GID_Chooser1],CHOOSER_Selected, 0, TAG_DONE);
   } else {
       IIntuition->SetAttrs(gad[GID_Chooser1],CHOOSER_Selected, 1, TAG_DONE);
   }

   return(ret);
}

void addbookmark(void) {
	struct Node *node;
	//printf("Add");
	/* First detach the list from the listbrowser before modifying anything */
	IIntuition->SetGadgetAttrs(gad[GID_Listbrowser1],win[WID_Window3],NULL,
			LISTBROWSER_Labels, ~0,
			TAG_DONE);
	/* We allocate a node for the listbrowser, and tell it to make an own copy of the string we supply via NodeString pointer, which is what we got from the string gadget but may change at any time */
	node = IListBrowser->AllocListBrowserNode(1,
			LBNCA_CopyText, TRUE,
			LBNCA_Text, NodeString,
			TAG_DONE);
	/* if the node allocation didn't fail we add it to our detached list */
	if(node)	IExec->AddTail(Ep_Listbrowser_BrowserList, node);
	/* and then we attach the list again to our lisbrowser */
	IIntuition->SetGadgetAttrs(gad[GID_Listbrowser1],win[WID_Window3],NULL,
			LISTBROWSER_Labels, Ep_Listbrowser_BrowserList,
			TAG_DONE);
	save_bookmarks(Ep_Listbrowser_BrowserList);
}

void editbookmark(void) {
	struct Node	*node;
	//printf("Edit");
	//Get the selected node
	IIntuition->GetAttr(LISTBROWSER_SelectedNode, gad[GID_Listbrowser1],(ULONG *)&node);

	if(node)
	{
	/* First detach the list from the listbrowser before modifying anything */
	IIntuition->SetGadgetAttrs(gad[GID_Listbrowser1],win[WID_Window3],NULL,
			LISTBROWSER_Labels, ~0,
			TAG_DONE);

	// Edit the selected node
	IListBrowser->SetListBrowserNodeAttrs(node, LBNCA_CopyText, TRUE, LBNCA_Text, NodeString, TAG_DONE);

	/* and then we attach the list again to our lisbrowser */
	IIntuition->SetGadgetAttrs(gad[GID_Listbrowser1],win[WID_Window3],NULL,
			LISTBROWSER_Labels, Ep_Listbrowser_BrowserList,
			TAG_DONE);
	} else {
		addbookmark();
	}
} 

void Button11_GadgetUp_Evt(void)
{
	struct Node *node;
	LONG test;
	/*
We got the selected node pointer we want to delete.
	*/
	IIntuition->GetAttrs(gad[GID_Listbrowser1],LISTBROWSER_SelectedNode, &node,TAG_DONE);

	/*
We check that the node really exists or it was selected before deleting it, otherwise it will crash and burn.
	*/

	if(node)
	{
		/* First detach the list from the listbrowser */
		IIntuition->SetGadgetAttrs(gad[GID_Listbrowser1],win[WID_Window3],NULL,
				LISTBROWSER_Labels, ~0,
				TAG_DONE);
		/*then we remove the node from the list*/
		IExec->Remove(node);
		/*and free the memory it gets*/
		IListBrowser->FreeListBrowserNode(node);
		/* once we're done deleting, we reattach the list to the listbrowser */
		IIntuition->SetGadgetAttrs(gad[GID_Listbrowser1],win[WID_Window3],NULL,
				LISTBROWSER_Labels, Ep_Listbrowser_BrowserList,
				TAG_DONE);
	}
	save_bookmarks(Ep_Listbrowser_BrowserList);
}

void Listbrowser1_GadgetUp_Evt(void)
{
	ULONG		result;
	struct Node	*node;
	//STRPTR	  *string;

	IIntuition->GetAttr(LISTBROWSER_RelEvent, gad[GID_Listbrowser1], &result);
	switch(result)
	{
		case LBRE_NORMAL:
			IIntuition->GetAttr(LISTBROWSER_SelectedNode, gad[GID_Listbrowser1],(ULONG *)&node);
			IListBrowser->GetListBrowserNodeAttrs(node,LBNCA_Text,&NodeString,TAG_DONE);
			break;
		case LBRE_DOUBLECLICK:
            IIntuition->GetAttr(LISTBROWSER_SelectedNode, gad[GID_Listbrowser1],(ULONG *)&node);
			IListBrowser->GetListBrowserNodeAttrs(node,LBNCA_Text,&urllink,TAG_DONE);
            showpage(urllink);
			break;
	}  
}

void OpenEditBookmarkWin(void)
{
	Ep_OpenWindow_Window4();

	IIntuition->SetWindowAttrs(win[WID_Window1], WA_BusyPointer, TRUE, TAG_DONE);
	IIntuition->SetWindowAttrs(win[WID_Window3], WA_BusyPointer, TRUE, TAG_DONE);
}

void Button9_GadgetUp_Evt(void)
{                           
	win4_opened = 1;
	node_todo = 2;                                                             

	OpenEditBookmarkWin();
	IIntuition->RefreshSetGadgetAttrs(gad[GID_String_4_1],win[WID_Window4],NULL,
			STRINGA_TextVal, NodeString,
			TAG_DONE);

}  

void Button10_GadgetUp_Evt(void)
{
    IIntuition->GetAttr(STRINGA_TextVal,gad[GID_String1],(ULONG*)&NodeString);
	if(strlen(NodeString) >0) {
		addbookmark();
	} else  {
		// Show the window4
		node_todo = 1;
        win4_opened = 1;
		OpenEditBookmarkWin();
        IIntuition->RefreshSetGadgetAttrs(gad[GID_String_4_1],win[WID_Window4],NULL,
			STRINGA_TextVal, NULL,
			TAG_DONE);
	}
}

BOOL save_bookmarks(struct List *list)
{
	FILE *fp;
	BOOL ret=FALSE;

	char *line;
	struct Node *node;

	if(fp=fopen(BKM_FILE,"wb"))
	{
		for (node = IExec->GetHead(list); node; node = IExec->GetSucc(node))
		{
			IListBrowser->GetListBrowserNodeAttrs(node,LBNCA_Text,&line,TAG_END);
			fprintf(fp,"%s\n", line);
			//FPuts (file,line);
			//FPutC (file,'\n');
		}
		ret	= TRUE;
		fclose(fp);
	}

	return(ret);
}

BOOL load_bookmarks(void)
{
	FILE *fp;
	BOOL ret=FALSE;
	char folder_suffix[256] = "fold";
	char line[256];
	long l;
	struct Node *node;
	int cmp;

	if(fp=fopen(BKM_FILE,"r"))
	{

		/* First detach the list from the listbrowser before modifying anything */
		IIntuition->SetGadgetAttrs(gad[GID_Listbrowser1],win[WID_Window3],NULL,
				LISTBROWSER_Labels, ~0,
				TAG_DONE);
		
		while(fgets(line, 256, fp))
			{
			if (l = strlen(line))
			{
				l --;
				if (line[l] == '\n')
					line[l] = 0;
			}

			cmp = strcmp(line, folder_suffix);
			printf("%d\n", cmp);
			if(!cmp) {
				node = IListBrowser->AllocListBrowserNode(1,
					LBNA_Generation, 1,
	                LBNA_Flags, LBFLG_HASCHILDREN | LBFLG_SHOWCHILDREN,
					LBNCA_CopyText, TRUE,
					LBNCA_Text, line,
					TAG_DONE);
		    } else {
				node = IListBrowser->AllocListBrowserNode(1,
					LBNA_Generation, 1,
					LBNCA_CopyText, TRUE,
					LBNCA_Text, line,
					TAG_DONE);
			}
            if(node)	IExec->AddTail(Ep_Listbrowser_BrowserList, node);
			}

		/* and then we attach the list again to our lisbrowser */
		IIntuition->SetGadgetAttrs(gad[GID_Listbrowser1],win[WID_Window3],NULL,
				LISTBROWSER_Labels, Ep_Listbrowser_BrowserList,
				TAG_DONE);

		ret	= TRUE;
		fclose(fp);
	}

	return(ret);
}

void Button_4_1_GadgetUp_Evt(void)
{
    IIntuition->GetAttr(STRINGA_TextVal,gad[GID_String_4_1],(ULONG*)&NodeString);
	//printf("%d \n", node_todo);
	switch (node_todo) {
		case 1:
			{
				addbookmark();
				break;
			}
		case 2:
			{
				editbookmark();
				break;
			}
	} 

	save_bookmarks(Ep_Listbrowser_BrowserList);
	Window4_CloseWindow_Evt();
}

