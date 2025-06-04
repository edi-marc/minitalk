# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 16:26:45 by emdi-mar          #+#    #+#              #
#    Updated: 2025/06/04 16:31:09 by emdi-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server 
CLIENT = client

SRCS =	ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_itoa.c ft_calloc.c ft_bzero.c ft_memset.c ft_atoi_s.c \
		ft_isdigit.c ft_strlcat.c ft_str_c_join.c send_char.c \
		decode_char.c \

U_SRCS = $(addprefix utils/, $(SRCS))

S_SRCS = server.c

S_SRCS_B = bonus/server_bonus.c

C_SRCS_B = bonus/client_bonus.c

C_SRCS = client.c

CC = cc
	
RM = /bin/rm -f

CFLAGS = -Wall -Wextra -Werror

CFLAGS_D = -Wall -Wextra -Werror -g 

INCLUDE_DIR = includes

OBJS = $(U_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $(<:.c=.o)

$(SERVER): $(OBJS)
	@echo "[server compilation...]"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(S_SRCS) $(OBJS) -o $(SERVER)

$(CLIENT): $(OBJS) $(SERVER)
	@echo "[client compilation...]"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(C_SRCS) $(OBJS) -o $(CLIENT)
	@make clean

clean:
	@echo "[cleaning...]"
	@$(RM) $(OBJS)

fclean: clean
	@echo "[hard cleaning...]"
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all

bonus: fclean $(OBJS)
	@echo "[server bonus compilation...]"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(S_SRCS_B) $(OBJS) -o $(SERVER) 
	@echo "[client bonus compilation...]"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(C_SRCS_B) $(OBJS) -o $(CLIENT)
	@make clean

debug: fclean $(OBJS)
	@$(CC) $(CFLAGS_D) -I$(INCLUDE_DIR) $(S_SRCS) $(OBJS) -o $(SERVER)
	@$(CC) $(CFLAGS_D) -I$(INCLUDE_DIR) $(C_SRCS) $(OBJS) -o $(CLIENT)
	@make clean

cdebug: fclean
	@$(RM) -r *.dSYM

.PHONY: all clean fclean re bonus debug cdebug
