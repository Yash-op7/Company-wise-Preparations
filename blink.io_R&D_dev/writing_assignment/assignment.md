# Progress Report:
- Completed general Interview Discussion.
- I think it went well
# Next Steps:
1. Provide 2 recommendations, so far got one
2. Assingment: Find at least 5 improvements to the product

# Assignment:
# Improvements/Innovations Discovered:

## 1. Ovecome Limited Customer Base Limitations
The current product has the following 2 major limitations:
1. It can only support automated testing for Javascript-based web applications as far as I could infer from the documentation, operating the platform, output logs and it's implementation details.
2. Even in JS based applications, the software must be a web hosted or a web browser accessible application which implies that either the application is hosted on the public internet or it's hosted on a locally accessible host with an URL, either way this is a strict requirement and it imposes a limit on the extent of softwares which could benefit from Gen-AI automated testing.

The implications of these two hard requirements of Blinq.io are that the majority of software owners wouldn't be able to leverage Blinq.io's pioneering idea of Automating Testing via Gen-AI. So one of the most important improvements or to be more accurate, next steps in the journey of perfectting Blinq.io is to expand it's capabilities to support alternate tech stacks and types of software systems such as testing of remote scripts, High Performance Computing (HPC) jobs, CLI applications, IoT systems, Blockchain infrastructures, and many more domains all of which can significantly benefit from a tool like Blinq.io, in my opinion.

## 2. Enhance Coverage and Robustness of the Underlying Gen-AI Model in Gherkin Code
Make the Gherkin operations more focussed and definitive, for example the demo project includes the following operation in the Gherkin code: 
```Gherkin
Then verify "Thank you for your order" can be found in the page
```
While this works for a simple application, it's not an advisable way to verify if an outcome of the operation is the intended one. In more complex applications, if we vaguely signal to the automated tester to check if a particular string exists or not in the entire webpage or current viewport, then it can open many new possibilities for judgement errors of the model. For example:
1. The string may be dynamic and not a fixed value, it may depend on values which cannot be gathered and passed to the tester beforehand, values which are computed at runtime due to external agents.
2. Another example is if we don't have the actual implementation of the code then we cannot simply say that if the output contains a particular string then our intended behavior has occurred because the string could be set to be hidden or encoded in the output UI and the tester may mistake some other occurrence which is not known to us for the intended occurrence, hence leading to an incorrect verdict.
> So in conclusion, an improvement would be to define strict unambiguous verification checks for the intended behavior, reducing the probability for interpretation errors.

## 3. Increase Flexibility of the `Record Scenario` Feature 
The `Record Scenario` feature seems to be fairly rigid in terms of the applications it can successfully record features of and understand to write the Gherkin code as it requires the application interface to have properly defined and labelled elements in the UI (like Email_input_field) but this is highly unlikely even in most properly made production grade software systems every element in the UI is not perfectly and distinctly labelled an the conversion from the Video to Gherkin code seems to lose information essential for complex scenarios such as movement patterns of the mouse or the what changes in the UI state result in what outcomes, so in this regard the  `Record Scenario` feature has room for improvement, namely in the following aspects:
- improve it's ability to comprehend more complex scenarios.
- improve it's abiltiy to predict and extrapolate, by deepening it's understanding of the user interface, instead of rigidly searching for exact matches of labels to element's percieved names by the AI.
- augment `Record Scenario`'s functionality to also allow speech input in the feature's recording, then the audio could be used as an additional input vector to better train the model to gain a deeper understanding of the user's motives and actions.

To test the flexibility or rigidity of the `Record Scenario` feature, I coded 3 simple web applications to test simple and straightforward operational logic via the  `Record Scenario` feature but the code while written following industry best practices and naming conventions, did not have automated testing as a future requirement in mind during development, what I mean is the code is easy to understand and properly labelled but the output UI does not contain proper labels as they were never a part of the requirements during the planning phase, the results indicated that this feature was not able to perform its most basic functions without error.
- It failed to detect all the click events, keyboard input events and alert events, in spite of the events being sparse.
- It failed to detect changes in the UI after detecting actions like clicks, the task was to test if the change theme button on a website works properly to toggle between light and dark modes.
- It misidentifies what the what the user is trying to imply in the UI in the most basic of scenarios. In the below two snapshots, I tried to test an application I built which is an inventory dashboard, it has a button for toggling between light and dark mode themes, there is no mention of a `Add to Cart` button in the entire code base nor is it part of the utility a dashboard should provide, but still every time I clicked the button the AI mistakenly extrapolated the change theme button, perhaps due to biases while training the model, leading it to associate any explicitly unlabelled element in the top right part of the header of a commercial website containing products to have the highest probability of being related to a Cart.
![alt text](<Screenshot 2024-09-18 at 1.39.22 PM.png>) ![alt text](<Screenshot 2024-09-18 at 1.39.09 PM.png>)

Please note that since I only experimented with the free version of Blinq.io, its quite possible that the application's quality and performance in terms of the intelligence and capabilities of the Generative AI model were capped at a cost efficient threshold since you are providing a free of cost demo of the app so to save computational costs, a new potential user may get a much rudimentary version of the application, so I cannot comment on the actual accuracy and intelligence of the AI model with certainity, but there is certainly scope of innovation in the capabilities and accuracy of the current Gen-AI model.

## 4. Generating realistic test data with increased coverage for edge cases:
Currently the platform relies on example driven testing or in other words behavior driven development. And it goes about this in two ways:
1. The AI infers the possible data values and uses simple and non-realistic examples (such as test_user for user name) to verify the intended behavior or it relies on randomly generated data (the example in the documentatin of a random string for a git repo init test), Or
2. Through an input CSV tables or User data in the Test Data section, while this is a more pragmatic approach it still relies on the user to provide the clean and processed CSV files, which isn't always convenient for most users.
> So here I would like to present the following attempt to innovate for better test coverage using self generated datasets:
1. Implement a functionality which is able to understand the correlation between various inputs and how they are processed, and generate on its own, a more diverse dataset with high variance, low correlation and realistic values to increase scenario coverage, it will more efficiently discover and test for edge cases, non-deterministic conditions and unexpected errors.


## 5. Incorporating other testing paradigms:

# Improvements in Implementation and UX details

## 1. Issues with the `Open with VSCode` utility
The `Open with VSCode` button doesn't seem to work in the free version of the product, but I constructed and ran the script as advised on the `Debugging Test Scripts in Visual Studio Code` documentaion page, the code bundle that is downloaded locally as a result of the script was missing the essential `.mjs` in the features directory, this was the primary motive for downloading the project test files. Also the documentation doesn't refer to this at all. The sample output and the platform interface also differs in key aspects compared to the current free version. I suspect it might be due to the documentation referring to either an older version or the paid version. 
The improvements that I would incorporate are:
- make the `Open with VSCode` button operational which currently is not working at all.
- provide a downloadable code bundle in the form of a `.zip` file which consists of the scenario description and the `.mjs` files in the `features` directory which are missing from the script's output, so if the user can just download the code bundle then they can locally work on understanding and polishing the test logic and use the JavaScript Debug Terminal successfully to debug the code using break points in any code editor of their choice.


## 6. UI Performance Improvements
The website interface can be improved in terms of the user experience by addressing performance issues caused by slow loading states between different aspects of the application. For example, since the web interface is a Single Page Application, different routes on the page can be and should be cached on the client side for a better snappy user experience, especially the ones which render static data on past tests and runs, for instance when you are on the `Features` page and you navigate to `Reports` or `Dashboard` there is a significant wait time not just for the first time you visit them but for every subsequent time as well in the same session, but since these pages render static data such as total number of features or information about `All Runs`, these can be easily cached for an instantaneous UX at the cost of minimal memory overhead, which is a very feasible tradeoff. There are more parts in the application which can benefit from client-side caching but I just mentioned these two as an example.
7. UI Appearance Improvements: The CSS styling is a bit off in a few places, for example the bottom left portion of the page where the exit button collides with the user name and email.
Another instance is in the `Scenario Outline` text box where there is no inherent word wrapping and it just continues to the right limiting readability of the entire scenario at any given instant and if you want to see the entire scenario you need to manually enter line breaks which not only provide irregular formatting but also add unnecessary characters in the input data which could mislead the AI's interpretation and degrade the results. Another CSS flaw is the overlapping of the Save and Cancel buttons in this same text box which are opaque and block the user input beneath them. These were some UI issues which can be fixed via CSS property modifications and prioritizing attention to detail.
The 
## 8. Incomplete/Sparse/Outdated documentation
I understand that this product is still undergoing development but I just wanted to mention this as a potential improvement.

   