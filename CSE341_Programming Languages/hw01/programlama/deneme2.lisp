(defun hello-world()
	(format t "hello world")
)



(defun garde-o (liste)
	(cond ((not liste) nil)
  		((equal (car liste) 'o) (cons (car liste) (garde-o (cdr liste))))
  		((garde-o (cdr liste)))
	)
)

(defun factoriel (x)
	(if(= x 0)
		1
		(* x (factoriel(- x 1)))
	)
)

(defun mymember2 (list1 list2)
	(cond ((not list2) nil)
  		((equal list1 (car list2)) (format t "bulduuu"))
  		((mymember2 (list1 (cdr list2))))
	)
)
