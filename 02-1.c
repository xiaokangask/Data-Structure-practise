List Merge(List L1,List L2)
{
	List head,p,p1,p2;
	head=(List)malloc(sizeof(struct Node));
	p=head;
	p1=L1->Next;
	p2=L2->Next;
	L1->Next=NULL;
	L2->Next=NULL;
	while(p1&&p2){
		if(p1->Data<p2->Data){
			p->Next=p1;
			p1=p1->Next;
			p=p->Next;
		}else if(p1->Data>p2->Data){
			p->Next=p2;
			p2=p2->Next;
			p=p->Next;
		}else if(p1->Data==p2->Data){
			p->Next=p1;
			p=p->Next;
			p1=p1->Next;
			p->Next=p2;
			p=p->Next;
			p2=p2->Next;
		}
	}
	if(p1) p->Next=p1;
	if(p2) p->Next=p2;
	return head;
}
