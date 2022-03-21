#pragma once
#pragma once
#pragma once
// სტეკისათვის განვსაზღვროთ დამხმარე კლასი mNode შაბლონის მეშვეობით
template <typename obj_type>
class mNode {
public:
	 obj_type data;  // შესანახი მონაცემის ტიპი
	 mNode* next;    // მიმთითებელი შემდეგ ელემენტზე
	 mNode* prev;    // მიმთითებელი წინა ელემენტზე 

	// კლასის კონსტრუქტორი
	 mNode<obj_type>(obj_type value, mNode* _prev = nullptr, mNode* _next = nullptr) :
		  data(value),
		  prev(_prev),
		  next(_next)
	 {}
};