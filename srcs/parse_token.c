/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:25:35 by seocha            #+#    #+#             */
/*   Updated: 2023/05/25 17:40:22 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse_token(t_token *token, char *s)
{
	//quote 분리
	parse_quote(token, s);
	//토큰 안의 $ 환경변수 해석
	
	//chunk로부터 공백을 찾아 space_token 분리
	//파이프라인을 기준으로 pipeline_token 분리
}