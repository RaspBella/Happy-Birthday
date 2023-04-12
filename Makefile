Happy-Birthday: Happy-Birthday.c
	cc $< -o $@

pdf: README.ms
	groff -ms -T pdf $< > README.$@

html: README.ms
	groff -ms -T html $< > README.$@

clean:
	rm -f Happy-Birthday
