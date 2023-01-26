char	**so_long()
{
	char	*line;
	int		fd;
	int i;

	i = 1;
	fd = open("map", O_RDONLY);
	line = get_next_line(fd);
	while (line[i])
	{	
		lige = get_next_line(fd);
		printf("%s", line);
		i++;
	}
}
int		main(void)
{
	char	**ligne;

	so_long(ligne);
}