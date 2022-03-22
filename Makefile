# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 20:13:33 by edi-marc          #+#    #+#              #
#    Updated: 2022/03/22 19:25:18 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server 
CLIENT = client

SRCS =	ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_itoa.c ft_calloc.c ft_bzero.c ft_memset.c \

U_SRCS = $(addprefix utils/, $(SRCS))

S_SRCS = server.c

C_SRCS = client.c

CC = gcc
	
RM = /bin/rm -f

CFLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = includes

OBJS = $(U_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $(<:.c=.o)

$(SERVER): $(OBJS)
	@echo "[server compilation...]"
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(S_SRCS) $(OBJS) -o $(SERVER)

$(CLIENT): $(OBJS) $(SERVER)
	@echo "[client compilation...]"
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(S_SRCS) $(OBJS) -o $(CLIENT)
	make clean

clean:
	@echo "[cleaning...]"
	$(RM) $(OBJS)

fclean: clean
	@echo "[hard cleaning...]"
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus bre
