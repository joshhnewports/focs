int eval(pNODE n)
{
    int val1, val2;
    
    if ((n->op) == 'i')  return n->value;
    else {
	val1 = eval(n->leftmostChild);
	if (n->leftmostChild->rightSibling == NULL) {
	    switch (n->op) {
	    case '+': return val1; // unary plus
	    case '-': return -val1; // unary minus
	    }
	}
	else {
	    val2 = eval(n->leftmostChild->rightSibling);
	    switch (n->op) {
	    case '+': return val1 + val2;
	    case '-': return val1 - val2;
	    case '*': return val1 * val2;
	    case '/': return val1 / val2;
	    }
	}
    }
}
