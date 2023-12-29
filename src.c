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
	// Litterals
	TT_NUM,

	// Other
	TT_OTHER,
	// Start of tokens
	TT_START,
	// End of things
	TT_EOL,
	TT_EOF
} TokenKinds;

typedef struct Token Token;

struct Token {
	TokenKinds kind;
	char* value;
	Token* nextToken;
};

int tokenize(size_t fd, Token* tokens) {
	
	char c = fgetc(fd);
	while (c) {
		
		if (c == '+') {
			puts("Token +\n");
		}

		c = fgetc(fd);
	}
		
	return 0;
}

int main(int argc, char** argv) {
	if (argc <= 1) {
		puts("Usage : ./smlc <file>\n");
		return 1;
	}

	ssize_t src_fd = open(argv[1], O_RDONLY, 0);

	if (src_fd <= 0) {
		puts("Cannot find file ");
		puts(argv[1]);
		puts("\n");
		return 1;
	}

	Token* tokens = {0};
	(void) tokenize(src_fd, tokens);

	(void) close(src_fd);

	return 0;
}
