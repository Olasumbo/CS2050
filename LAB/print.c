int calcPrint(Node* root, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
    int width = 5;
	
 	if (!root) return 0;
    sprintf(b, "(%03d)", root->value);
	int left  = calcPrint(root->left,  1, offset, depth + 1, s);
    int right = calcPrint(root->right, 0, offset + left + width, depth + 1, s);

	int i;
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (i = 0; i < width + right; i++)
	       s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }

	return left + width + right;
}

//SAME AS THE FUNCTION ABOVE
void printTree(Node* root)
{
	char s[20][255];
	int i;
	for(i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");
	
	calcPrint(root, 0, 0, 0, s);
	for(i = 0; i < 20; i++)
	{
		printf("%s\n", s[i]);
	}
}
