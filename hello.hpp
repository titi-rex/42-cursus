
#ifndef _hello_H__
# define _hello_H__
# include <lb>

class hello {
	
	private	:
		int	_priv;
		char*	_name;

	public	:
		hello(void);
		~hello(void);
		getPriv(void) const;
		setPriv(int priv);
		getName(void) const;
		setName(char* name);
		c	cd;
};

#endif
