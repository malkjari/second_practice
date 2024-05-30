SUBDIRS = libmysyslog libmysyslog-text libmysyslog-json libmysyslog-client libmysyslog-daemon

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

deb:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir deb; \
	done

repo:
	# Команды для создания репозитория
	dpkg-scanpackages . /dev/null | gzip -9c > Packages.gz

.PHONY: all clean deb repo
