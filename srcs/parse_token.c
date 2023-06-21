/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:57:46 by ricecha           #+#    #+#             */
/*   Updated: 2023/06/21 21:56:26 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 주어진 문자열을 알맞는 토큰으로 분리
t_token	*parse_main(char *str)
{
	t_token	*token;

	if (token == NULL)
		return (NULL);
	token->type = TOKEN_ORIGIN;
	token->origin = str;
	token->next = NULL;
	parse_quote(token); // 따옴표 분리(quote로 묶인 환경변수 처리)
	parse_env(token); // 환경변수 분리(quote없는 환경변수 처리)
	parse_space(token); // 공백 분리
	parse_pipeline(token); // 파이프라인 분리
	parse_redirection(token); // 리다이렉션 분리
	parse_delete_empty_chunkc(token); // 비어있는 토큰 분리
	parse_chunk_to_argv(token); // 나머지 토큰을 argv로 치환
	parse_merge_argv(token); // 연속한 argv 토큰들 병합
	parse_delete_space(token); // 공백 삭제
}
