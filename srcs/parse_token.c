/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricecha <ricecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:57:46 by ricecha           #+#    #+#             */
/*   Updated: 2023/06/02 22:14:48 by ricecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_token   *parse_main(char *str)
{
    # token 순서대로 쪼개기
    t_token *token;

    if (token == NULL)
        return (NULL);
    token->type = TOKEN_ORIGIN;
    token->original = str;
    parse_quote(token);
    parse_env(token);
    parse_space(token);
    parse_pipeline(token);
    parse_redirection(token);
    parse_delete_empty_chunk(token);
    parse_chunk_to_argv(token);
    parse_merge_argv(token);
    parse_delete_space(token);
}