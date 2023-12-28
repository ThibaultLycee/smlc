#include "smlclib.c"

/*
 *	Source code of smlc
 * */

typedef enum {
	// Binary operators
	TT_PLUS,
	TT_MINUS,
	TT_MUL,
	TT_DIV,
	TT_AND,
	TT_OR,
	TT_XOR,
	// idk
	TT_TYPE,
	TT_ASSIGN,
	// Comparison
	TT_EQU,
	TT_LT,
	TT_GT,
	TT_LTEQ,
	TT_GTEQ,
	TT_NEQ,

	// End of things
	TT_EOL,
	TT_EOF
} TokenKinds;

typedef struct {
	TokenKinds kind;
	char* value;
} Token;

int tokenize(size_t fd, Token* tokens) {
	return 0;
}

int main(int argc, char** argv) {
	if (argc <= 1) {
		puts("Usage : ./puts <file>\n");
		return 1;
	}

	ssize_t src_fd = open(argv[1], O_RDONLY, 0);

	if (src_fd >= 0)
		(void) close(src_fd);
	else
		puts("Failed to open\n");

	return 0;
}
