# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 20:13:33 by edi-marc          #+#    #+#              #
#    Updated: 2022/03/21 20:45:18 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server 
CLIENT = client

SRCS = 

U_SRCS = $(addprefix utils/, $(SRCS))

S_SRCS = server.c

C_SRCS = client.c

CC = gcc
	
RM = /bin/rm -f

CFLAGS = -Wall -Wextra -Werror	

all: $(SERVER)

$(SERVER):
	$(CC) $(CFLAGS) $(U_SRCS) $(S_SRCS)  
	@make clean	

clean:
	@$(RM) $(OBJS) $(BOBJS)

fclean: clean
	@$(RM) $(NAME)

bonus: $(OBJS) $(BOBJS) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJS) $(BOBJS)
	@make clean

re: fclean all

bre: fclean bonus

.PHONY: all clean fclean re bonus bre
