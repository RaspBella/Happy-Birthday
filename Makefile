Happy-Birthday: Happy-Birthday.c
	cc $< -o $@

README.pdf: README.ms
	groff -ms -T pdf $< > $@

clean:
	rm -f Happy-Birthday
