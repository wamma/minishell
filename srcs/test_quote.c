#include <stdlib.h>
#include <stdio.h>

#define TOKEN_CHUNK 0
#define TOKEN_ARGV 1
#define TOKEN_SPACE 2
#define TOKEN_PIPELINE 3
#define TOKEN_R 4
#define TOKEN_RR 5
#define TOKEN_L 6
#define TOKEN_LL 7

typedef struct s_token
{
	int type;
	char *original; // quote 짝 체크
	char *str;      // quote를 제외한 문자열, 환경변수를 해석하기 전 문자열. $ 유무 체크
	struct s_token *next;
} t_token;

t_token *create_node(int type, char *original, char *str, t_token *node)
{
	t_token *new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->type = type;
	new_node->original = original;
	new_node->str = str;
	if (node != NULL)
		node->next = new_node;
	return (new_node);
}

static int is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

static char *arr_argv(const char *str, int len)
{
	char *word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		fprintf(stderr, "Error: Failed to allocate memory for word.\n");
		exit(1);
	}
	for (int i = 0; i < len; i++)
		word[i] = str[i];
	word[len] = '\0';
	return word;
}

static char *arr_chunk(const char *str, int len)
{
	char *word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		fprintf(stderr, "Error: Failed to allocate memory for word.\n");
		exit(1);
	}
	for (int i = 0; i < len; i++)
		word[i] = str[i];
	word[len] = '\0';
	return word;
}

static void push_quote(const char **s)
{
	if (**s == '\'')
	{
		(*s)++;
		while (**s && **s != '\'')
			(*s)++;
	}
	else if (**s == '\"')
	{
		(*s)++;
		while (**s && **s != '\"')
			(*s)++;
	}
}

void parse_quote(t_token **token, const char *s)
{
	int i = 0;
	t_token *node = NULL;

	if (!s)
		return;
	while (s[i])
	{
		while (s[i] && is_quote(s[i]))
			i++;
		if (s[i] == '\0')
			break;
		int len = 0;
		const char *temp = &s[i];
		while (temp[len] && !is_quote(temp[len]))
			len++;
		node = create_node(TOKEN_CHUNK, arr_chunk(&s[i], len), arr_argv(&s[i], len), *token);
		if (*token == NULL)
			*token = node;
		push_quote(&s);
		i += len;
	}
}

int main(void)
{
	t_token *token = NULL;
	const char *s = "echo \"hello world\" 'hello world'";

	parse_quote(&token, s);
	while (token)
	{
		printf("type: %d\n", token->type);
		printf("original: %s\n", token->original);
		printf("str: %s\n", token->str);
		printf("\n");
		token = token->next;
	}
	return (0);
}
