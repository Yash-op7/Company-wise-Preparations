npm init -y
npm install @dev-blinq/cucumber-js
npx cross-env  node ./node_modules/@dev-blinq/cucumber-js/bin/download-install.js --token 82c1846fc59346068fe007148ce17823 --extractDir 66ea7635369bab78d1683426
cd 66ea7635369bab78d1683426
npm init -y
npm install @dev-blinq/cucumber_client automation_model @dev-blinq/cucumber-js
npx playwright install
npx cross-env BLINQ_ENV=environments/prod.json TOKEN=82c1846fc59346068fe007148ce17823 BVT_FORMATTER="ANALYSIS" cucumber-js --format bvt --tags "@debug"

