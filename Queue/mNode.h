#pragma once
// სტეკისათვის განვსაზღვროთ დამხმარე კლასი mNode შაბლონის მეშვეობით
template <typename obj_type>
class mNode {
public:
	 obj_type data;  // შესანახი მონაცემის ტიპი
	 mNode* next;     // მიმთითებელი შემდეგ ელემენტზე

	// კლასის კონსტრუქტორი
	mNode<obj_type>(obj_type value, mNode* link = nullptr):
		  data(value),
		  next(link)
	 {}	
};

